/**
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array. 
 * The number of elements initialized in nums1 and nums2 are m and n respectively. 
 * You may assume that nums1 has a size equal to m + n such that it has enough space to hold additional elements from nums2.
 * 
 * Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3 
 * Output: [1,2,2,3,5,6]
 * 
 * Input: nums1 = [0], m = 0, nums2 = [1], n = 1
 * Output: [1]
 * 
 * https://leetcode.com/explore/interview/card/microsoft/47/sorting-and-searching/258/
 * */


// Basic Concept - Start from the end
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1; int j = n-1; int k = m+n-1;
        while(i >=0 && j >=0){
            if(nums1[i] > nums2[j]){ 
                nums1[k] = nums1[i];
                i--; k--;
            }
            else{ 
                nums1[k] = nums2[j]; 
                k--; j--; 
            }
        }
        // TestCase [0] 0 [1] 1
        while(j >= 0){ nums1[k--] = nums2[j--]; }
    }
};