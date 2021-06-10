/**
 * Given an array nums with n objects colored red, white, or blue, sort them in-place 
 * so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
 * We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
 * You must solve this problem without using the library's sort function.
 * 
 * Input: nums = [2,0,2,1,1,0]
 * Output: [0,0,1,1,2,2]
 * 
 * https://leetcode.com/explore/interview/card/microsoft/47/sorting-and-searching/193/discuss/1252665/C++-Solution-or-Double-Pass-or-Single-Pass
 * */

// Approach 1: Two Pass Solution + O(m+n) Space
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size(); int k = 0; int j = 0;
        int num0 = 0; int num1 = 0; int num2 = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == 0){ num0++; }
            else if(nums[i] == 1){ num1++; }
            else if(nums[i] == 2){ num2++; }
        }
        
        for(int i=0; i<num0; i++){ nums[i] = 0; }
        for(int i=0; i<num1; i++){ nums[num0 + i] = 1; }
        for(int i=0; i<num2; i++){ nums[num0 + num1 + i] = 2; }
    }
};

// Approach 2: Single Pass Solution
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size(); int k = 0; int j = 0;
        int red = -1; int white = -1; int blue = -1;
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                nums[++blue] = 2; // The ordering is very important
                nums[++white] = 1;
                nums[++red] = 0;
            }
            else if(nums[i] == 1){
                nums[++blue] = 2;
                nums[++white] = 1; 
            }
            else if(nums[i] == 2){
                nums[++blue] = 2;
            }
        }
    }
};