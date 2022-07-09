/**
 * Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
 * The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
 * You must write an algorithm that runs in O(n) time and without using the division operation.
 * 
 * Input: nums = [1,2,3,4]      Output: [24,12,8,6]
 * Input: nums = [-1,1,0,-3,3]  Output: [0,0,9,0,0]
 * 
 * https://leetcode.com/problems/product-of-array-except-self/
 * */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int fromBegin = 1; int fromLast = 1;
        vector<int> result(n,1);
        
        for(int i = 0; i < n; i++){
            result[i] = fromBegin*result[i];
            fromBegin = fromBegin*nums[i];
            
            result[n-i-1] = fromLast*result[n-i-1];
            fromLast = fromLast*nums[n-i-1];
            cout<<"B "<<fromBegin<<" L "<<fromLast<<endl;
            
        }
        return result;
    }
};
/**
nums = [1,2,3,4]
fromBegin = [1] => [1,1,2,6,24]
fromLast  = [1] => [1,4,12,24,24]
**/ 