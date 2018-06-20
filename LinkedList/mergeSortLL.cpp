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

Node* midptr(Node*head){		//Get
	if(head==NULL || head->next==NULL)
		return head;
	Node* fast = head;		//Set
	Node* slow = head;
	//Go
	while(slow && fast && fast->next && fast->next->next){
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

Node* mergeSortedLists(Node* a,Node* b){
	if(a == NULL)	return b;
	if(b == NULL)	return a;

	if(a->data < b->data){
		a->next = mergeSortedLists(a->next,b);
		return a;
	}
	else{
		b->next = mergeSortedLists(a,b->next);
		return b;
	}

}

Node* mergeSort(Node* head){
	if(head==NULL || head->next==NULL)
		return head;

	Node* middle = midptr(head);
	Node* l1 = head;
	Node* l2 = middle->next;
	middle->next = NULL;
	l1 = mergeSort(l1);
	l2 = mergeSort(l2);
	Node* ans = mergeSortedLists(l1,l2);
	return ans;
}

int main(){
	Node* head = createLL();
//	print(head);
	head = mergeSort(head);
	print(head);
}
