#include <iostream>
#include <algorithm> 
using namespace std;
int reduce(int n){
    int dp[100] = {0};
    // Base Case
    if(n==1)
        return 0;
    for (int i=2; i <= n ;i++){
        int x = 10000,y = 10000,z = 10000;
        if(i%3 == 0){
            x = dp[i/3] + 1;
        }
        else if(i%2 == 0){
            y = dp[i/2] + 1;
        }
        z = dp[i-1] + 1;
        dp[i] = min(y,z);
        dp[i] = min(x,dp[i]);
        //cout<<"X -> "<<x<<"Y -> "<<y<<"Z ->"<<z<<" "<<dp[i]<<endl;
    }
    return dp[n];
}
int main() {
    int n;
    cin>>n;
    int ans = reduce(n);
    cout<<ans;
}
