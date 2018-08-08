//We can reduce the no either : 1. divide by 3 2. divide by 2 3. reduce by 1

#include <iostream>
#include <algorithm>
using namespace std;
const int inf = (int)1e9;
#define MIN(x,y) (x<y?x:y)
int memo[1000];

//Top Down Approach
int reduce(int n){
    if(n == 1)
        return 0;
    int q1 = inf, q2 = inf, q3 = inf;
    if(n%3 == 0)    q1 = 1 + reduce(n/3);
    if(n%2 == 0)    q2 = 1 + reduce(n/2);
    q3 = 1 + reduce(n-1);
    memo[n] = MIN(q1,MIN(q2 , q3));
    return memo[n];
}

//Bottom Up Approach
int reduceNo(int n){
    int dp[10000];
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    for(int curNum = 4;curNum <= n;curNum++){
        int q1 = inf, q2 = inf, q3 = inf;
        if(curNum%3 == 0)   q1 = 1 + dp[curNum/3];
        if(curNum%2 == 0)   q2 = 1 + dp[curNum/2];
        q3 = 1 + dp[curNum-1];
        dp[curNum] = MIN(q1, MIN(q2,q3));
    }
    return dp[n];
}

int main() {
    int n;
    cin>>n;
    fill(memo,memo+n+1,-1);     //Can use for loop here
    int ans = reduceNo(n);
    cout<<ans;
    return 0;
}

//Input : 10
//Output: 3
//Catch : it shouldn't be 4
