/**
 * Given an integer array nums, find the contiguous subarray (containing at least one number) which has
 *  the largest sum and return its sum.
 * 
 * Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * 
 * */
// Greedy Approach
class Solution {
public:
    //Kadane's Algorthm
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int current_sum = 0, best_sum = INT_MIN;
        for(int i=0;i < n;i++){
            current_sum = max(nums[i],current_sum+nums[i]);
            best_sum = max(best_sum, current_sum);
        }
        return best_sum;
    }
};
/**
nums = [-2,1,-3,4,-1,2,1,-5,4]
current_sum = 0  max_sum = 0
current_sum =-2  max_sum =-2
current_sum = 1  max_sum = 1
current_sum =-2  max_sum = 1
current_sum = 4  max_sum = 4
current_sum = 3  max_sum = 4
current_sum = 5  max_sum = 5
current_sum = 6  max_sum = 6
current_sum = 1  max_sum = 6
current_sum = 5  max_sum = 6

**/

// DP Based Approach
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(); 
        int dp[n]; dp[0] = nums[0];
        int best_sum = dp[0];
        for(int i=1;i < n;i++){
            dp[i] = max(nums[i],dp[i-1]+nums[i]);
            best_sum = max(best_sum, dp[i]);
        }
        return best_sum;
    }
};





