/**
 * Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 * Note that you must do this in-place without making a copy of the array.
 * 
 * Input: nums = [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 * */

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0; int n = nums.size();
        for(int i = 0; i<n; i++){
            if(nums[i] != 0){
                nums[j++] = nums[i];
            }
        }
        while(j < n){
            nums[j++] = 0;
        }
    }
};