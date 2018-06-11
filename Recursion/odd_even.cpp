/*  Take as input N, a number.
Print odd numbers in decreasing sequence (up until 0) and 
even numbers in increasing sequence (up until N) using Recursion
*/

#include <iostream>
using namespace std;

void odd(int n){
	if(n==1){
		cout<<1<<endl;
		return ;
	}
	cout<<n<<endl;
	odd(n-2);
}
void even(int n,int i){
	if(n==2){
		cout<<2<<endl;
		return;
	}
	if(i<=n){
		cout<<i<<endl;
		even(n,i+2);
	}
}
int main(){
	int n;
	cin>>n;
	if(n%2 == 0){
		odd(n-1);
		even(n,2);
	}
	else{
		odd(n);
		even(n-1,2);
	}
}

//Input 5
//Output
/*
5
3
1
2
4
*/
