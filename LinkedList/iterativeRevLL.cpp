#include <iostream>
using namespace std;

class Node{
public:
	int data;
	Node* next;
	Node(int d){
		data = d;
	}
};

Node* createLL(int n){
	int x;
	Node* head = NULL;
	Node* tail = NULL;
	while(n>0){
		cin>>x;
//		if(x == -1)
//			break;
		Node* newnode = new Node(x);
		if(head == NULL){
			head = newnode;
			tail = newnode;
		}
		else{
			tail->next = newnode;
			tail = tail->next;
		}
		n--;
	}
	return head;
}

void print(Node*head){
	Node*temp = head;
	if(temp == NULL)
		return;
	while(temp->next != NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<temp->data;
	cout<<endl;
}

Node* reverse(Node*head){
	Node* curr,* nextnode,* prev;
	curr = head;
	prev = NULL;
	if(head==NULL || head->next==NULL)
		return head;
	while(curr != NULL){
		nextnode = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nextnode;
	}
	head = prev;
	return head;
}

int main(){
	int n;
	cin>>n;
	Node* head = createLL(n);
//	print(head);
	head = reverse(head);
	print(head);
}
