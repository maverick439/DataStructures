//Reverse a Stack using Recursion.

#include <iostream>
#include <stack>
using namespace std;

stack<int> s;

void insertatBottom(int x){
	if(s.size() == 0)
		s.push(x);
	else{
		int a = s.top();
		s.pop();
		insertatBottom(x);
		s.push(a);
	}
}
void reverse(){
	if(s.empty())
		return;
	if(s.size()>0){
		int x = s.top();
		s.pop();
		reverse();
		insertatBottom(x);
	}
} 

int main(){
	int n,x;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		s.push(x);
	}
	reverse();
	while(!s.empty()){
		cout<<s.top()<<endl;
		s.pop();
	}
	return 0;
}
