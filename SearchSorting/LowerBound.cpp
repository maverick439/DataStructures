
// Lower Bound = First occurence of a particular element in an array of elements with duplicates as well

#include <iostream>
using namespace std;

int lowerbound(int arr[],int n,int key){
    int l = 0;
    int r = n-1;
    int ans = -1;
    while(l <= r){
        int mid = (l+r)/2;
        if(key == arr[mid]){
            ans = mid;
            r = mid-1;
        }
        if(key > arr[mid]){
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    return ans;
}

int upperbound(int arr[],int n,int key){
    int l = 0;
    int r = n-1;
    int ans = -1;
    while(l <= r){
        int mid = (l+r)/2;
        if(key == arr[mid]){
            ans = mid;
            l = mid+1;
        }
        else if(key < arr[mid]){
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return ans;
}


int main() {
    int n,key;
    int arr[100];
    cin>>n;
    int i;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>key;
    int lower = lowerbound(arr,n,key);
    cout<<"Lower Bound : "<<lower;
    
    int upper = upperbound(arr,n,key);
    cout<<"Upper Bound : "<<upper;
}

/*
Input :
7
1 1 2 2 2 2 4
2

Output : 
lower = 2
upper = 5
*/
