/**
 * Replace All ?'s to Avoid Consecutive Repeating Characters
 * https://leetcode.com/problems/replace-all-s-to-avoid-consecutive-repeating-characters/
 * 
 * Input: s = "ubv?w"
 * Output: "ubvaw"
 * Explanation: There are 24 solutions for this problem. Only "v" and "w" are invalid modifications 
 * as the strings will consist of consecutive repeating characters in "ubvvw" and "ubvww".
 * 
 * Input: s = "?zs"
 * Output: "azs"
 * Explanation: There are 25 solutions for this problem. From "azs" to "yzs", all are valid. 
 * Only "z" is an invalid modification as the string will consist of consecutive repeating characters in "zzs".
 * 
 * */

class Solution {
public:
    string modifyString(string s) {
        int n = s.size();
        for(int i=0; i<n; i++){
            if(s[i] == '?'){
                char temp = 'a';
                bool flag = false;
                while(!flag){
                    flag = true;
                    if((i<n-1 && s[i+1] == temp) || (i>0 && s[i-1] == temp)){
                        temp = temp+1;
                    }
                    if(i<n-1 && s[i+1] == temp){ flag = false; }
                    if(i>0 && s[i-1] == temp){ flag = false; }
                }
                s[i] = temp;  
            }
        }
        return s;
    }
};