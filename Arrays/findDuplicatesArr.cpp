/**
 * Given an integer array nums of length n where all the integers of nums are in the range [1, n] and 
 * each integer appears once or twice, return an array of all the integers that appears twice.
 * You must write an algorithm that runs in O(n) time and uses only constant extra space.
 * 
 * Input: nums = [4,3,2,7,8,2,3,1]  Output: [2,3]
 * */

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result; 
        int n = nums.size();
        
        for(int i=0; i < n; i++){
            int index = abs(nums[i]) - 1;
            if(nums[index] > 0){
                nums[index] = -nums[index];   
            }
            else{
                result.push_back(index + 1);
            }
        }
        return result; 
    }
};