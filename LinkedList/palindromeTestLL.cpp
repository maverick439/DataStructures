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
    bool isPalindrome(ListNode* head) {
        if(!head){ return true; }
        if(head->next == NULL){ return true; }
        ListNode*slow = head;
        ListNode*fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast != NULL){ slow = slow->next; }
        slow = reverseList(slow);
        fast = head;
        while(slow){
            if(slow->val != fast->val){
                return false;
            }
            slow = slow->next;
            fast = fast->next;
        }
        return true;
    }
private:
    ListNode*reverseList(ListNode*head){
        if(!head){ return NULL; }
        if(head->next == NULL){ return head; }
        ListNode*prev = NULL;
        ListNode*current = head;
        while(current){
            ListNode*after = current->next;
            current->next = prev;
            prev = current;
            current = after;
        }
        return prev;
    }
    
};