/**
 * Given an integer array nums and an integer val, 
 * remove all occurrences of val in nums in-place. 
 * The relative order of the elements may be changed.
 * 
 * Input: nums = [3,2,2,3], val = 3
 * Output: 2, nums = [2,2,_,_]
 * 
 * Input: nums = [0,1,2,2,3,0,4,2], val = 2
 * Output: 5, nums = [0,1,4,0,3,_,_,_]
 * */

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size(); int count = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == val){ count++; }
            else{ nums[i-count] = nums[i]; }
        }
        return n-count;
    }
};