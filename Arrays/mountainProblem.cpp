/**
 * Given an array of integers arr, return true if and only if it is a valid mountain array.
 * Recall that arr is a mountain array if and only if:
 * arr.length >= 3
 * There exists some i with 0 < i < arr.length - 1 such that:
 * arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
 * arr[i] > arr[i + 1] > ... > arr[arr.length - 1
 * 
 * Input: arr = [2,1]
 * Output: false
 * 
 * Input: arr = [0,3,2,1]
 * Output: true
 * */

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();  int i = 0;
        if(arr.size() < 3){ return false; }
        
        //While going up 
        while(i < n-1 && arr[i] < arr[i+1]){
            i++;
        }
        if(i == 0 || i == n-1 ){ return false; }
        
        // While going down
        while(i < n-1 && arr[i+1] < arr[i]){
            i++;
        }
        if(i == n-1){ return true; }
        return false;
    }
};