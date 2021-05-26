/**
 * You are given two non-empty linked lists representing two non-negative integers. 
 * The most significant digit comes first and each of their nodes contains a single digit. 
 * Add the two numbers and return the sum as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 * 
 * Input: l1 = [7,2,4,3], l2 = [5,6,4]
 * Output: [7,8,0,7]
 * Explanantion: 3+4 = 7 : 4+6 = 10 : 2+5+1=8 
 * 
 * 
 * */

// Add LL backwards
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int>s1;  stack<int>s2;
        while(l1){ s1.push(l1->val); l1 = l1->next; }
        while(l2){ s2.push(l2->val); l2 = l2->next; }
        ListNode*prev = NULL; ListNode*current = NULL;
        int sum = 0; int carry = 0;
        while(!s1.empty() || !s2.empty()){
            sum = carry;
            if(!s1.empty()){ sum += s1.top(); s1.pop(); }
            if(!s2.empty()){ sum += s2.top(); s2.pop(); }
            carry = sum/10;
            prev = new ListNode(sum%10);
            prev->next = current;
            current = prev;
            sum = 0;
        }
        if(carry > 0){ 
            prev = new ListNode(carry);
            prev->next = current;
            current = prev;
        }
        return current;
    }
};

/**
 * 
 * Input: l1 = [2,4,3], l2 = [5,6,4] 
 * Output: [7,0,8]
 * Explanation: 342 + 465 = 807.
**/
//Add LL frontwards
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