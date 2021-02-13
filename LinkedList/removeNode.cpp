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

// Iterative Approach
    ListNode* removeElements(ListNode* head, int val) {
        if(!head){ return NULL; }
        if(head->next == NULL && head->val == val){ return NULL; }
        ListNode*prev = new ListNode(0);
        prev->next = head;
        ListNode*temp = prev;
        while(temp){
            if(temp->next && temp->next->val == val){
                temp->next = temp->next->next;
            }
            else{
                temp = temp->next;
            }
        }
        return prev->next;
    }

    // Recursive Approach
    ListNode* removeElements(ListNode* head, int val) {
        if(!head){ return NULL; }
        if(head->next == NULL && head->val == val){ return NULL; }
        if(head->val == val){
            return removeElements(head->next,val);
        }
        head->next = removeElements(head->next,val);
        return head;
    }