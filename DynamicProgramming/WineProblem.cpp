#include <iostream>
#include <cstring>
using namespace std;
int memo[100][100];
int maxProfit(int arr[],int be,int en,int year){
    if(be > en)
        return 0;
    if(memo[be][en] != -1)
        return memo[be][en];
    int c1 = arr[be]*year + maxProfit(arr,be+1,en,year+1);
    int c2 = arr[en]*year + maxProfit(arr,be,en-1,year+1);
    int ans = max(c1,c2);
    memo[be][en] = ans;
    return ans;

}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int ans = maxProfit(arr,0,n-1,1);
    cout<<ans;
}

/*
Input
5
2 3 5 1 4
Output
50
*/
