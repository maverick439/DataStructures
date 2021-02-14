#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL){ return l2; }
        if(l2 == NULL){ return l1; }
        ListNode head(0);
        ListNode*temp = &head;
        int total = 0;
        while(l1 || l2){
            if(l1){ total += l1->val; l1 = l1->next; }
            if(l2){ total += l2->val; l2 = l2->next; }
            temp->next = new ListNode(total % 10);
            total /= 10;
            temp = temp->next;
        }
        if(total%10 == 1){
            temp->next = new ListNode(total % 10);
            temp = temp->next;
        }
        return head.next;
    }
};
