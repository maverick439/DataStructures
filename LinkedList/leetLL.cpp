// Singly Linked List 
// Traversal Time -> O(n)
// Adding a new Node -> O(1)
// Deleting a new Node -> O(N)
using namespace std;
#include <iostream>

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    int val;
    int len;
    MyLinkedList*next;
    MyLinkedList*head;
    
    MyLinkedList() {
        next = NULL;
        head = NULL;
        len = 0;
    }

    MyLinkedList(int v) {
        val = v;
        next = NULL;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        MyLinkedList*temp = head;
        if(index < 0){ return -1; }
        for(int i=0;i<index;i++){
            temp = temp->next;
        }
        if(temp){ return temp->val; }
        else{ return -1; }
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        MyLinkedList*temp = new MyLinkedList(val);
        temp->next = head;
        head = temp;
        len++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        MyLinkedList*newNode = new MyLinkedList(val);
        if(head == NULL){ head = newNode; }
        else{
            MyLinkedList*temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
            len++;
        }
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        MyLinkedList*newNode = new MyLinkedList(val);
        if(index>len or index<0){ return; }
        else if(index == 0){ addAtHead(val); }
        else if(index == len){ addAtTail(val); }
        else{
            MyLinkedList*temp = head;
            int count = 0;
            while(temp){
                if(count == index-1){ break; }
                temp = temp->next;
                count++;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            len++;            
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index >= len){ return; }
        else if(index == 0){ 
            head = head->next; 
            return;
        }
        else{
            int count = 0;
            MyLinkedList*temp = head;
            while(temp){
                if(count == index-1){ break; }
                temp = temp->next;
                count++;
            }
            temp->next = temp->next->next;
            len--;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
