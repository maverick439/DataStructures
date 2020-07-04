//Sliding Window problem
#include <iostream>
using namespace std;

long long int flipOnes(long long int arr[],long long int n,long long int k){
    //Left and right index
    long long int leftIndex = 0,rightIndex = 0;
    // Left Index and window size and zeroes
    long long int zeroCount = 0, bestWindow = 0, startIndex = 0;

    while(rightIndex < n){
        if (zeroCount <= k){
            if(arr[rightIndex] == 0) 
                zeroCount++; 
            rightIndex++;
        }
        if(zeroCount > k){
            if(arr[leftIndex] == 0)
                zeroCount--; 
            leftIndex++;
        }
        if ((rightIndex - leftIndex > bestWindow) && (zeroCount <= k)){
            bestWindow = rightIndex - leftIndex;
            startIndex = leftIndex;
        }
    }
    // Array indexes
    for(long long int i=0;i<bestWindow;i++){
        if(arr[i+startIndex] == 0)
            arr[i+startIndex] = 1;
    }
    cout<<bestWindow<<endl;
    for(long long int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

int main() {
    long long int n,k;
    cin>>n>>k;
    long long int arr[n];
    for(long long int i=0;i<n;i++)
        cin>>arr[i];
    int ans = flipOnes(arr,n,k);
}
