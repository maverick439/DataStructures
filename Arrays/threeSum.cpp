/**
 * Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
 * such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
 * Notice that the solution set must not contain duplicate triplets.
 * 
 * Input: nums = [-1,0,1,2,-1,-4]
 * Output: [[-1,-1,2],[-1,0,1]]
 * 
 * https://leetcode.com/problems/3sum/
 * */


// O(N*N) Solution | Two pointer 
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            // To avoid duplicates
            if(i>0 && nums[i] == nums[i-1])
                continue; 
            
            int start = i+1; int end = n-1;
    
            // Two pointer technique
            while(start < end){
                int sum = nums[i] + nums[start] + nums[end];
                // No point iterating for sum > 0 since sorted arr
                if(sum > 0){ end--; }
                else if(sum < 0){ start++; }
                // Avoid the case where all values are 0
                else{
                    ans.push_back(vector<int> {nums[i], nums[start], nums[end]} );
                    // To avoid duplicates
                    while(start < end && nums[start] == nums[start+1]){ start++; }
                    while(start < end && nums[end] == nums[end-1]){ end--; }
                    start++; end--;
                }
            }
        }
        return ans;
    }
};