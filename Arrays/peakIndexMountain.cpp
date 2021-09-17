/**
 * https://leetcode.com/problems/peak-index-in-a-mountain-array/
 * 
 * Let's call an array arr a mountain if the following properties hold:
 * arr.length >= 3
 * There exists some i with 0 < i < arr.length - 1 such that:
 * arr[0] < arr[1] < ... arr[i-1] < arr[i]
 * arr[i] > arr[i+1] > ... > arr[arr.length - 1]
 * Given an integer array arr that is guaranteed to be a mountain, 
 * return any i such that arr[0] < arr[1] < ... arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].
 * 
 * */

// O(Log N) Solution Binary Search
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0; int end = arr.size()-1;
        while(start < end){
            int mid = (start+end)/2;
            if(arr[mid] < arr[mid+1]){
                start = mid+1;
            }
            else{
                end = mid;
            }
        }
        return start;
    }
};

// O(N) Solution
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int large = INT_MIN; int index = 0;
        for(int i=0; i<arr.size(); i++){
            if(arr[i] > large){
                large = max(large, arr[i]);
                index = i;
            }
        }
        return index;
    }
};
