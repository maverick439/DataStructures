#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main(){
    int nums = [2,3,1,1,4];
    int jumps = jump(nums);
    cout<<"Min Jumps : "<<jumps;
}

int jumps(vector<int>& nums){
    int n = nums.size();
    vector<int> dp(n, INT_MAX-1);
    dp[0] = 0;

    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(nums[j] + j >= i){
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }
    return dp[n-1];
}