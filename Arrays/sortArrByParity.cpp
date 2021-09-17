/**
 * Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.
 * 
 * Input: nums = [3,1,2,4]
 * Output: [2,4,3,1]
 * Explanation: The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
 * 
 * */

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int start = 0; int end = n-1;
        while(start < end){
            if(nums[start]%2 == 0){
                start++;
            }
            
            else{
                if(nums[end]%2 == 0){
                    swap(nums[start], nums[end]);
                    start++; end--;
                }
                else{
                    end--;
                }
            }
        }
        return nums;
        
    }
};