#include <stdio.h>
#include <stdlib.h>

int main(){
	int n,i,d;
	printf("Enter no of elements\n");
	scanf("%d",&n);
	int arr[n];
	printf("Enter elements\n");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);

	reverse(arr,0,n-1);

	for(i=0;i<n;i++)
		printf(" %d ",arr[i]);
	
}

int reverse(int arr[],int l,int n){
	while(l<n){
		int temp = arr[l];
		arr[l] = arr[n];
		arr[n] = temp;
		l++;
		n--;
	}
}
