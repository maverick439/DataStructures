/* Missing number in array
Given an array C of size N-1 and given that there are numbers from 1 to N with one element missing, 
the missing number is to be found.
9
1 2 3 4 5 6 7 8 10
Output : 9 */

#include <iostream>
#include <climits>
using namespace std;

//Approach1 : Using sum
int MissingEle(int arr[],int n){
    int x = n+1;
    int exp_sum = 0; int actual_sum = 0;
    exp_sum = (x*(x+1))/2;
    for(int i=0;i<n;i++){
        actual_sum += arr[i];
    }
    int mis_no = exp_sum - actual_sum;
    return mis_no;
}

//Approach2: Using Xor
int XorMethod(int arr[],int n){
    int x1 = arr[0];
    int x2 = 1;
    for(int i=1;i<n;i++)
        x1 = x1^arr[i];
    for(int i=2;i<=n+1;i++)
        x2 = x2^i;
    int res = x1^x2;
    return res;
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int res1 = MissingEle(arr,n);
    int res2 = XorMethod(arr,n);
    cout<<"Approach 1: "<<res1<<endl<<"Approach 2: "<<res2;
}
