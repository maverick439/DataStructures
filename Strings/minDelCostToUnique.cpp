/**
 * Minimum Deletion Cost to Avoid Repeating Letters
 * 
 * Given a string s and an array of integers cost where cost[i] is the 
 * cost of deleting the ith character in s.
 * Return the minimum cost of deletions such that there are no two identical letters next to each other.
 * 
 * Imp Test Case
 * Input : "aaabbbabbbb" , [3,5,10,7,5,3,5,5,4,8,1]
 * Output: 26
 * 
 * https://leetcode.com/problems/minimum-deletion-cost-to-avoid-repeating-letters/
 * */

class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int result = 0;
        if(s.length() == 0){ return result; }
        int sum = 0; int i = 1;
        while(i < s.length()){
            if(s[i] == s[i-1]){
                sum += min(cost[i],cost[i-1]);
                 cost[i] = max(cost[i],cost[i-1]); //important for continuous same chars
                i++;
            }
            else{ 
                i++;
            }
        }
        return sum;
    }
};


