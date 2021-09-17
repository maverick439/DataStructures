/**
 * Given integer array nums, return the third maximum number in this array. 
 * If the third maximum does not exist, return the maximum number.
 * 
 * Input: nums = [3,2,1]    Output: 1   Explanation: The third maximum is 1.
 * 
 * Input: nums = [1,2]      Output: 2   Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
 * 
 * Input: nums = [2,2,3,1]     Output: 1
 * Explanation: Note that the third maximum here means the third maximum distinct number.
 * Both numbers with value 2 are both considered as second maximum.
 * */

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long first_max = LONG_MIN, second_max = LONG_MIN, third_max = LONG_MIN;
        int n = nums.size();
        if(n == 1){ return nums[0]; }
        if(n == 2){ return max(nums[0], nums[1]); }
        
        for(int i : nums){
            if(i > first_max){
                third_max = second_max;
                second_max = first_max;
                first_max = i;
            }
            else if(i == first_max){ continue; }
            else if(i > second_max){
                third_max = second_max;
                second_max = i;
            }
            else if(i == second_max){ continue; }
            else if(i > third_max){
                third_max = i;
            }
        }
        cout<<first_max<<second_max<<third_max;
        if(third_max == LONG_MIN){ return (int)first_max; }
        return (int)third_max;
    }
};

