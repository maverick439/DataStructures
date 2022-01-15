/**
 * Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
 * Input: nums = [1,2,3]
 * Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * */

/**
Basic Idea: Backtracking
[ 1 2 3]     [1 3 2] swap j, j+1
swap i,i+1
[ 2 1 3]
[ 3 2 1]
**/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;
        backtrack(permutations, nums, 0);
        return permutations;
    }
    
    void backtrack(vector<vector<int>>&permutations, vector<int>nums, int start){
        if(start == nums.size()-1)
            permutations.push_back(nums);
        
        for(int i = start; i < nums.size(); i++){
            swap(nums[start], nums[i]);
            backtrack(permutations, nums, start+1);
            swap(nums[start], nums[i]);
        }
    }
};
