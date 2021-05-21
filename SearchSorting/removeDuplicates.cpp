/**
 * Given a sorted array nums, remove the duplicates in-place such that each element appears only once and returns the new length.
 * Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
 * 
 * Input: nums = [0,0,1,1,1,2,2,3,3,4]
 * Output: 5, nums = [0,1,2,3,4]
 * 
 * https://leetcode.com/explore/interview/card/microsoft/47/sorting-and-searching/257/
 * */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int duplicate_count = 0;
        int n = nums.size();
        for(int i=1;i < n;i++){
            if(nums[i] == nums[i-1]){ duplicate_count++; }
            else{ nums[i-duplicate_count] = nums[i]; }
        }
        return n-duplicate_count;
    }
};