/**
 * Given a list of non-negative integers nums, arrange them such that they form the largest number.
 * Note: The result may be very large, so you need to return a string instead of an integer.
 * 
 * Input: nums = [27, 4]
 * Output: 427
 * 
 * https://leetcode.com/problems/largest-number/discuss/53157/A-simple-C%2B%2B-solution
 * */

class Solution {
struct comp{
    bool operator() (int a, int b){
        string comb1 = to_string(a) + to_string(b);
        string comb2 = to_string(b) + to_string(a);
        return comb1 > comb2;
    }
} mycomp;
public:
    string largestNumber(vector<int>& nums) {
        string ans;
        // s1+s2>s2+s1 trick
        sort(nums.begin(), nums.end(), mycomp);
        if(nums[0] == 0){ return "0"; }
        for(auto num : nums){
            ans += to_string(num);
        }
        return ans;
    }
};