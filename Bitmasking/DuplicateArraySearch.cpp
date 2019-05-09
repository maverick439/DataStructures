//If an array has all duplicates except one. find it in O(n) and O(1) space.
#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    //Method 1 (Print all repeating elements)
    // for(int i=0;i<n;i++){
    //     if(arr[abs(arr[i])] >= 0)
    //         arr[abs(arr[i])] = -arr[abs(arr[i])];
    //     else
    //         cout<<abs(arr[i])<<" ";
    // }

    //Method 2 (Print the one element which is not repeating)
    int x = arr[0];
    for (int i=1;i<n;i++){
        x = x^arr[i];
    }
    cout<<x<<endl;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
