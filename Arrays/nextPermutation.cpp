// According to Wikipedia, a man named Narayana Pandita presented the following simple algorithm to solve this problem in the 14th century.

// 1. Find the largest index k such that nums[k] < nums[k + 1]. If no such index exists, just reverse nums and done.
// 2. Find the largest index l > k such that nums[k] < nums[l].
// 3. Swap nums[k] and nums[l].
// 4. Reverse the sub-array nums[k + 1:].


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size()-1;
        int p = -1, pv = 0;
        for(int i=n-1;i >= 0;i--){
            if(nums[i] < nums[i+1]){
                p = i;
                pv = nums[i];
                break;
            }
        }
        //Last permutation
        if(p == -1){ 
            reverse(nums,0,n); 
            return;
        }
        for(int i=n;i >= 0; i--){
            if(nums[i] > pv){
                swap(nums,p,i);
                break;
            }
        }
        reverse(nums, p + 1, n);
    }
    void reverse(vector<int>& nums, int s, int e){
      while(s < e){
        swap(nums, s, e);
        s++;
        e--;
      }
    }
    
    void swap(vector<int>& nums, int s, int e){
        int t = nums[s];
        nums[s] = nums[e];
        nums[e] = t;     
    }
};
