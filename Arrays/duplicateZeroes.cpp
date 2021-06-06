/**
 * Given a fixed length array arr of integers, duplicate each occurrence of zero, shifting the remaining elements to the right.
 * Note that elements beyond the length of the original array are not written.
 * Do the above modifications to the input array in place, do not return anything from your function.
 * 
 * 
 * Input: [1,0,2,3,0,4,5,0]
 * Output: null
 * Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]
 * 
 * https://leetcode.com/problems/duplicate-zeros/
 * 
 * */

//Approach 1
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int dope = 0; int n = arr.size();
        for(int i= 0; i < n; i++){
            if(arr[i] == 0){
                arr.pop_back();
                arr.insert(arr.begin()+i, 0);
                i++;
            }
        }
    }
};

//Approach 2
// https://leetcode.com/problems/duplicate-zeros/discuss/505107/C%2B%2B%3A-two-pass-shift-counter-fast-simple-explanation
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size(); int shift = 0;
        for(int i=0;i<n;i++){ 
            if(arr[i] == 0){ shift++; }
        }
        for(int i= n-1; i >= 0; i--){
            if(arr[i] == 0){ shift--; }
            if(i+shift < n){
                arr[i+shift] = arr[i];
                if(arr[i] == 0 && i+shift+1<n){
                    arr[i + shift + 1] = 0;
                }
            }
        }
        
    }
};
