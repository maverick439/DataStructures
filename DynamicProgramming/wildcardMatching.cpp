/**
 * Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
 * The matching should cover the entire input string (not partial).
 * 
 * Input: s = "adceb", p = "*a*b"
 * Output: true
 * Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
 * 
 * https://leetcode.com/explore/interview/card/microsoft/46/backtracking/155/discuss/1001130/C++-Clean-and-concise-bottom-up-dp-code-with-detailed-explanation-easy-to-understand.
 * 
 * */

// Approach 1 : Time - O(m*n) Space - O(m*n)
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>>dp(s.size() + 1, vector(p.size() + 1, false));
        // Initial value to build on
        dp[0][0] = true;
        for(int j=0; j < p.size() && p[j] == '*'; j++){
            dp[0][j+1] = true;
        }
        for(int i=1;i <= s.size();i++){
            for(int j=1;j <= p.size();j++){
                if(p[j-1] == '*'){
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
                else{
                    dp[i][j] = (s[i-1] == p[j-1] || p[j-1] == '?') && dp[i-1][j-1];
                }
            }
        }
        return dp[s.size()][p.size()];
        
    }
};