/**
 * Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.
 * 
 * */

class Solution {
public:
    // O(N) Solution
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int result = nums[0];
        for(int i = 0;i <= n/2;i++){
            int min_no = min(nums[i],nums[n-i-1]);
            result = min(result, min_no);
        }
        return result;
    }
    // O(Log N) Solution
    int findMin(vector<int>& nums) {
        int end = nums.size() - 1; int start = 0;
        int result = nums[0];
        while(start < end){
            // No rotations
            if(nums[start] < nums[end]){ return nums[start]; }
            
            int mid = (start+end)/2;
            // No rotations encountered yet
            if(nums[mid] >= nums[start]){ start = mid+1; }
            else{ end = mid; }
        }
        return nums[start];
    }
};