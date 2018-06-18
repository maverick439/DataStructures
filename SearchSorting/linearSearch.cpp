#include <iostream>
using namespace std;

int linearsearch(int arr[],int n,int ele){
	for(int i=0;i<n;i++){
		if(arr[i] == ele)
			return i;
	}
	return -1;
}
int main(){
	int n;
	int arr[50];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int ele;
	cin>>ele;
	int pos = linearsearch(arr,n,ele);
	cout<<pos<<endl;
}
