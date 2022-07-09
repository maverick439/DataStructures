/**
 * 
 * Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations 
 * of candidates where the chosen numbers sum to target. You may return the combinations in any order.
 * 
 * Input: candidates = [2,3,6,7], target = 7 
 * Output: [[2,2,3],[7]]
 * Explanation:
 * 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
 * 7 is a candidate, and 7 = 7.
 * These are the only two combinations
 * https://leetcode.com/problems/combination-sum/
 * */


class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> ds;
        backtrack(result, candidates, 0, target, ds);
        return result;
    }
    
    void backtrack(vector<vector<int>>& result, vector<int> nums, int index, int target, vector<int>& ds){
        if(index == nums.size()){
            if(target == 0){
                result.push_back(ds);
            }
            return;
        }
        
        // Pickup element
        if(nums[index] <= target){
            ds.push_back(nums[index]);
            backtrack(result, nums, index, target - nums[index], ds);
            ds.pop_back();
        }
        // Non-Pickup element
        backtrack(result, nums, index+1, target, ds);
    }
};