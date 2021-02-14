#include <iostream>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        recursiveFlatten(head);
        return head;
    }
    Node*recursiveFlatten(Node*head){
        if(head == NULL){ return head; }
        if(head->child == NULL){
            if(head->next == NULL){ return head; }
            return recursiveFlatten(head->next);
        }
        Node*child = head->child;
        Node*nextNode = head->next;
        head->child = NULL;
        Node*childTail = recursiveFlatten(child);
        head->next = child;
        child->prev = head;
        if(nextNode){
            childTail->next = nextNode;
            nextNode->prev = childTail;
            return recursiveFlatten(childTail);
        }
        return childTail;
    }
};
