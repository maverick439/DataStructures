#include <iostream>
using namespace std;
void subsetSums(int arr[],int l,int r,int sum=0){
	if(l>r){
		cout<<sum<<" ";
		return ;
	}
	//Subsets including arr[l]
	subsetSums(arr,l+1,r,sum+arr[l]);

	//Subsets excluding arr[l]
	subsetSums(arr,l+1,r,sum);
}
int main(){
	int n,sum,i;
	int arr[100];
	cin>>n;
	for(i=0;i<n;i++){
		cin>>arr[i];
	}
	subsetSums(arr,0,n-1);
}
