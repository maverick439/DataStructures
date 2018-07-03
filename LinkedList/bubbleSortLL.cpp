#include <iostream>
using namespace std;
int n;
class Node{
public:
    int data;
    Node* next;     // self referential classes
    Node(int d){
        data = d;
        next = NULL;
    }
};

Node* createLL(){
    int x;
    Node* head = NULL;
    Node* tail = NULL;

    while(n){
        cin >> x;
    //    if (x == -1) break;
        Node* newNode = new Node(x);
        if (head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = tail->next;
        }
        n--;
    }
    return head;
}

void print(Node*head){
	Node*temp = head;
	if(temp==NULL)
		return;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;

}

int lenLL(Node* head){
    Node* cur = head; 
    int cnt = 0;
    while(cur){ 
    	++cnt; 
    	cur = cur->next;
    }
    return cnt;
}

Node* bubbleSort(Node* head){
    int len = lenLL(head);
    int cnt = len;
    for(int i = 0; i < len; ++i){
        Node* cur = head;
        Node* previous = NULL;
        while(cnt && cur && cur->next){
            Node* ahead = cur->next;
            if(cur->data > ahead->data){
                // swapping needs to be done
                if (previous == NULL){
                    cur->next = ahead->next;
                    ahead->next = cur;
                    head = ahead;
                    previous = ahead;
                }
                else{
                    cur->next = ahead->next; 
                    previous->next = ahead;
                    ahead->next = cur;
                    previous = ahead;
                }
            }
            else{
                previous = cur;
                cur = cur->next;
            }
        }
        --cnt;
    }
    return head;
}

int main(){
	cin>>n;
	Node* head = createLL();
	Node* sorted = bubbleSort(head);
	print(sorted);
}
