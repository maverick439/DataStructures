/**
 * 
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they 
 * add up to target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * 
 * Input: nums = [2,7,11,15], target = 9 
 * Output: [0,1]
 * Output: Because nums[0] + nums[1] == 9, we return [0, 1].
 * https://leetcode.com/explore/interview/card/microsoft/30/array-and-strings/173/
 * 
 * */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>hash;
        vector<int>soln;
        for(int i=0; i< nums.size(); i++){
            int find_num = target - nums[i];
            if(hash.find(find_num) != hash.end()){
                soln.push_back(hash[find_num]);
                soln.push_back(i);
            }
            hash[nums[i]] = i;
        }
        return soln;
    }
};