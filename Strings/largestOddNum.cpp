/**
 * You are given a string num, representing a large integer. 
 * Return the largest-valued odd integer (as a string) that is a non-empty substring of num, 
 * or an empty string "" if no odd integer exists.
 * A substring is a contiguous sequence of characters within a string.
 * 
 * https://leetcode.com/problems/largest-odd-number-in-string/
 * */

/**
Concept - 
Find the first odd number from the last
Note: Do not try with int/long etc TLE
**/

class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size()-1;
        for(int i=n; i>=0; i--){
            if((num[i]-'0')%2 != 0){
                return num.substr(0,i+1);
            }
        }
        return "";
    }
};