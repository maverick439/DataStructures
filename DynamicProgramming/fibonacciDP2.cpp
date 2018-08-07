#include <iostream>
using namespace std;

//Bottom Up Approach

int fibo(int n){
    int dp[1000] = {};
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2;i <= n;i++)
        dp[i] = dp[i-1] + dp[i-2];
    int ans = dp[n];
    return ans;
}
int main() {
    int n;
    cin>>n;
    int ans = fibo(n);
    cout<<"Fibonacci of "<<n<<" is  "<<ans;
    return 0;
}
