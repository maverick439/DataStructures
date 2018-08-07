//We can reduce the no either : 1. divide by 3 2. divide by 2 3. reduce by 1

#include <iostream>
#include <algorithm>
using namespace std;
const int inf = (int)1e9;
#define MIN(x,y) (x<y?x:y)
int memo[1000];

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

int main() {
    int n;
    cin>>n;
    fill(memo,memo+n+1,-1);     //Can use for loop here
    int ans = reduce(n);
    cout<<ans;
    return 0;
}

//Input : 10
//Output: 3
//Catch : it shouldn't be 4
