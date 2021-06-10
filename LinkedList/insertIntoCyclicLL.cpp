/**
 * Given a Circular Linked List node, which is sorted in ascending order, write a function to insert a value insertVal into the list such that it remains a sorted circular list. 
 * The given node can be a reference to any single node in the list and may not necessarily be the smallest value in the circular list.
 * If there are multiple suitable places for insertion, you may choose any place to insert the new value. After the insertion, the circular list should remain sorted.
 * If the list is empty (i.e., the given node is null), you should create a new single circular list and return the reference to that single node. 
 * Otherwise, you should return the originally given node.
 * 
 *  1 - - - - - -
 *  |           \
 *  |           \
 *  4 - - - - - 3
 * 
 *  Insert 2
 *  
 *  1 - - - - - 2
 *  |           \
 *  |           \
 *  4 - - - - - 3
 * 
 * https://leetcode.com/explore/learn/card/linked-list/213/conclusion/1226/discuss/136918/(Accepted)-C++-Solution-in-O(n)-with-Explanation
 * */

/**
Concept:
Insert New Node When:
1. Prev <= InsertVal <= After 
2. InsertVal < min (Insert At the tail)
3. InsertVal > max (Insert At the tail)
**/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if(head == NULL){
            head = new Node(insertVal, NULL);
            head->next = head;
            return head;
        }
        Node*prev = head;
        Node*after = head->next;
        while(!(prev->val <= insertVal && insertVal <= after->val) && 
            !(prev->val > after->val && insertVal > prev->val) &&
            !(prev->val > after->val && insertVal < after->val)){

            prev = prev->next;
            after = after->next;
            if(prev == head){ break; }
        }
        prev->next = new Node(insertVal, after);
        return head;
    }
};