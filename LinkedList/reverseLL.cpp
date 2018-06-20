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

Node* createLL(){
	int x;
	Node* head = NULL;
	Node* tail = NULL;
	while(x){
		cin>>x;
		if(x == -1)
			break;
		Node* newnode = new Node(x);
		if(head == NULL){
			head = newnode;
			tail = newnode;
		}
		else{
			tail->next = newnode;
			tail = tail->next;
		}
	}
	return head;
}

void print(Node*head){
	Node*temp = head;
	if(temp == NULL)
		return;
	while(temp->next != NULL){
		cout<<temp->data<<"--> ";
		temp = temp->next;
	}
	cout<<temp->data;
	cout<<endl;
}

Node* reverse(Node*head){
	if(head==NULL || head->next==NULL)
		return head;
	Node* remainingList = reverse(head->next);
	head->next->next = head;
	head->next = NULL;
	return remainingList;
}

int main(){
	Node* head = createLL();
	print(head);
	head = reverse(head);
	print(head);
}
