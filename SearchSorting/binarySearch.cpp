#include <iostream>
using namespace std;

int binarysearch(int arr[],int n,int ele){
	int l = 0;
	int r = n-1;
	while(l<=r){
		int mid = (l+r)/2;
		if(ele == arr[mid])
			return mid;
		if(ele > arr[mid]){
			l = mid+1;
		}
		if(ele < arr[mid]){
			r = mid -1;
		}
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
	int pos = binarysearch(arr,n,ele);
	cout<<pos<<endl;
}

/**
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0; int end = nums.size()-1;
        while(start <= end){
            int mid = (start+end)/2;
            if(target > nums[mid]){ start = mid + 1; }
            if(target < nums[mid]){ end = mid - 1; }
            if(target == nums[mid]){ return mid; }
        }
        return -1;
    }
};
**/