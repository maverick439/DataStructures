#include <iostream>
using namespace std;

int largestsearch(int arr[],int n){
	int large = arr[0];
	int i;
	for(i=1;i<n;i++){
		if(arr[i] > large)
			large = arr[i];
	}
	return large;
}
int main(){
	int n;
	int arr[50];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int pos = largestsearch(arr,n);
	cout<<pos<<endl;
}
