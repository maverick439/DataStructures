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
	printf("The no times you want to rotate\n");
	scanf("%d",&d);
	rotate(arr,d,n);
	
	printf("\nAfter Left Rotation \n");
	for(i=0;i<n;i++)
		printf("  %d  ",arr[i]);
}
int rotate_one(int arr[],int n){
	int temp = arr[0];
	int i=0;
	for(i=0;i<n-1;i++)
		arr[i] = arr[i+1];
	arr[i] = temp;
}
int rotate(int arr[],int d,int n){
	for(int i=0;i<d;i++)
		rotate_one(arr,n);
}

/* Alternate Method
Use a separate temporary array.
arr = {1,2,3,4,5} d=2
temp = {1,2}
arr = {3,4,5,4,5}
arr = [3,4,5,1,2]
O(n)
