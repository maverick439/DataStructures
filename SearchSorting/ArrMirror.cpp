#include <iostream>
using namespace std;

bool arrmirror(int arr[],int n){
	int i = 0;
	int j = n-1;
	while(i<j){
		if(arr[i] != arr[j]){
			cout<<"false";
			return false;
		}
		else{
			i++;
			j--;
		}
	}
	cout<<"true";
	return true;
}
int main(){
	int n,i;
	int arr[50];
	cin>>n;
	for(i=0;i<n;i++){
		cin>>arr[i];
	}
	bool ans = arrmirror(arr,n);
	//	return 0;	
}
