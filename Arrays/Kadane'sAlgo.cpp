//Largest Sum Contiguous Subarray

#include <iostream>
#include <climits>
using namespace std;

int MaxSubArr(int arr[],int n){
    int max_ending = 0; int max_final = INT_MIN;
    for(int i=0;i<n;i++){
        max_ending = max_ending + arr[i];
        if(max_ending < 0)
            max_ending = 0;
        else if(max_final < max_ending){
            max_final = max_ending;
        }
    }
    return max_final;
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int res = MaxSubArr(arr,n);
    cout<<res;
}
