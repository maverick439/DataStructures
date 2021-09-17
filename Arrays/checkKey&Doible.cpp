/**
 * Given an array arr of integers, check if there exists two integers N and M such that N is the double of M ( i.e. N = 2 * M).
 * 
 * Input: arr = [10,2,5,3]
 * Output: true
 * 
 * Input: arr = [3,1,7,11]
 * Output: false
 * */

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> set;
        for(int i=0; i< arr.size(); i++){
            if((set.find(2*arr[i]) != set.end()) || (arr[i]%2 == 0 && set.find(arr[i]/2) != set.end())){ 
                return true; 
            }
            else{
                set.insert(arr[i]);
            }
        }
        return false;
    }
};