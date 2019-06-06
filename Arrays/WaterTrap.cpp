//https://www.geeksforgeeks.org/trapping-rain-water/

#include <iostream>
using namespace std;

int WaterTrapped(int arr[],int n){
    int left[n],right[n];
    int water = 0;
    //Aligning from the left
    left[0] = arr[0];
    for(int i=1;i<n;i++)
        left[i] = max(left[i-1],arr[i]);
    //Aligning from the right
    right[n-1] = arr[n-1];
    for(int i=n-2;i>=0;i--)
        right[i] = max(right[i+1],arr[i]);
        
    //Water Space
    for(int i=0;i<n;i++)
        water += min(left[i],right[i]) - arr[i];
    
    return water;
    
}

int main() {
	int t;
	cin>>t;
	while(t>0){
	    int n;
    	cin>>n;
    	int arr[n];
    	for(int i=0;i<n;i++)
    	    cin>>arr[i];
    	    
    	int res = WaterTrapped(arr,n);
    	cout<<res<<endl;
    	t--;
	}
	return 0;
}
