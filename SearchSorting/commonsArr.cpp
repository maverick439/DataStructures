/*
7
1 2 3 1 2 4 1
2 1 3 1 5 2 2

Sample Output:
[1, 1, 2, 2, 3]

Print all commons in both arrays
*/
#include <iostream>
using namespace std;
int a[50];
int k;
void commons(int arr1[],int arr2[],int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(arr1[i] == arr2[j]){
				a[k++] = arr1[i];
				arr2[j] = -1;
				break;
			}
		}
	}
}
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
	int n,i;
	int arr1[50];
	int arr2[50];
	cin>>n;
	for(i=0;i<n;i++)
		cin>>arr1[i];
	for(i=0;i<n;i++)
		cin>>arr2[i];
	commons(arr1,arr2,n);
	insertionsort(a,k);
	cout<<"[";
	for(i=0;i<k-1;i++){
		cout<<a[i]<<", ";
	}
	cout<<a[i]<<"]";
	
}
