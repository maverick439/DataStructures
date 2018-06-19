#include <iostream>
using namespace std;
void selectionsort(int arr[],int n){
	int i,j,minIndex;
	for(i=0;i<n-1;i++){
		minIndex = i;
		for(j=i+1;j<n;j++)
			if(arr[j]<arr[minIndex])
				minIndex = j;
			int temp = arr[minIndex];
			arr[minIndex] = arr[i];
			arr[i] = temp;
		
	}
}

int main(){
	int arr[50];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	selectionsort(arr,n);
	for(int i=0;i<n;i++)
		cout<<arr[i]<<endl;
}
