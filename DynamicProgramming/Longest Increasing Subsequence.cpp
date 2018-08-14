//Longest Increasing Subsequence
#include <iostream>
#include <cstring>
using namespace std;

int countLIS(int arr[],int n){  //BottomUp
    int LIS[n];
    int i,j,mx=0;
    for(i=0;i<n;i++)
        LIS[i] = 1;
    for(i=1;i<n;i++){
        for(j=0;j<i;j++){
            if((arr[i] > arr[j]) && (LIS[i] < LIS[j] + 1)){
                LIS[i] = LIS[j] + 1;
            }
        }
    }
    for(i=0;i<n;i++){
        if(LIS[i] > mx)
            mx = LIS[i];
    }
    return mx;
}
int main() {     
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int ans = countLIS(arr,n);
    cout<<ans;
}

// The length of LIS for {10, 22, 9, 33, 21, 50, 41, 60, 80} is 6 and
// LIS =  {10, 22, 33, 50, 60, 80}.
