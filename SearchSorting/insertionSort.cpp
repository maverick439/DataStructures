#include <iostream>
using namespace std;

void insertionsort(int arr[],int n){
	int i,key,j;
	for(i=1;i<n;i++){
		key = arr[i];
		j = i-1;
		while(j>=0 && arr[j]>key){
			arr[j+1] = arr[j];
			j = j-1;
		}
		arr[j+1] = key;
	}
}
int main(){
	int arr[20];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	insertionsort(arr,n);
	for(int i=0;i<n;i++)
		cout<<arr[i]<<endl;
}
