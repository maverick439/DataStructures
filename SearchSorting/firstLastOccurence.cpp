/**
 * Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
 * If target is not found in the array, return [-1, -1].
 * You must write an algorithm with O(log n) runtime complexity.
 * 
 * Example 1:
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * */

// Solution 1
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0; int end = nums.size() - 1;
        vector<int> res(2,-1);
        
        while(start <= end){
            int mid = start + (end - start)/2;
            if(nums[mid] > target){ end = mid - 1; }
            else if(nums[mid] < target){ start = mid + 1; }
            else if(nums[mid] == target){
                if(start == mid || nums[mid] != nums[mid-1]){ 
                    res[0] = mid; 
                    break;
                }
                else{ end = mid-1; res[0] = mid-1; }
            }
        }
        
        start = 0; end = nums.size()-1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(nums[mid] > target){ end = mid - 1; }
            else if(nums[mid] < target){ start = mid + 1; }
            else if(nums[mid] == target){
                if(mid == end || nums[mid] != nums[mid+1]){ 
                    res[1] = mid; 
                    break;
                }
                else{ 
                    start = mid+1; 
                    res[1] = mid+1; 
                    }
                }
            }
        
        return res;
    }
};

// Solution 2
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2,-1);
        
        int idx1 = lower_bound(nums, target);
        int idx2 = lower_bound(nums, target+1)-1;
        
        if(idx1 < nums.size() && nums[idx1] == target && nums[idx2] == target)
            return {idx1, idx2};
        
        return {-1,-1};
    }
    
    int lower_bound(vector<int> nums, int target){
        int start = 0;  int end = nums.size()-1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(nums[mid] < target){ start = mid+1; }
            else{ end = mid-1; }
        }
        return start;
    }
};