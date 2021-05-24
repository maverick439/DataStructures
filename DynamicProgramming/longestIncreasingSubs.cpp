/**
 * Algo:
 * nums = [10,9,2,5,3,7,11,18]
 * i = upper iterator
 * j = lower iterator
 * 
 * lis =  [1, 1,1,1,1,1, 1, 1]
 * 
 * if(nums[i] > nums[j] && lis[i] <= lis[j])
 * lis[i] = 1 + lis[j]
 * 
 * */

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int lis[n]; 
        lis[0] = 1;
        int i = 1;
        int j = 0;
        int length = 1;
        for(i = 1;i < n;i++){
            lis[i] = 1;
            for(j = 0;j < i;j++){
                if(nums[i] > nums[j] && lis[i] <= lis[j]){
                    lis[i] = 1 + lis[j];
                    length = max(length, lis[i]);
                }
            }
        }
        return length;
    }
};