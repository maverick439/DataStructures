#include <iostream>
using namespace std;

void arrRev(int arr[],int n){
	int i = 0;
	int j = n-1;
	while(i<j){
		int temp = arr[j];
		arr[j] = arr[i];
		arr[i] = temp; 
		i++;
		j--;
	}
}

int main(){
	int n,i;
	int arr[50];
	cin>>n;
	for(i=0;i<n;i++){
		cin>>arr[i];
	}
	arrRev(arr,n);
	for(i=0;i<n;i++){
		cout<<arr[i]<<endl;
	}
	return 0;	
}
