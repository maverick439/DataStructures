/*
Basic algo: 
1. Reverse each word now
2. Reverse the entire string 


Input: "the sky is blue"
Step 1: "eht yks si eulb"
Step 2: "blue is sky the"
https://leetcode.com/problems/reverse-words-in-a-string/submissions/
*/

#include <stack>
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        if(n == 0){ return s; }
        int i = 0; int j = 0;
        while(i < n){
            while(i < n && s[i] == ' '){ i++; } // remove initial space
            if(i < n && j > 0){ s[j++] = ' '; } 
            int start = j;
            while(i < n && s[i] != ' '){
                s[j++] = s[i++];
            }
            reverse(s.begin()+start, s.begin()+j);
        }
        s.resize(j); // Remove unwanted space
        reverse(s.begin(),s.end()); // Reverse the entire word
        return s;
    }
};