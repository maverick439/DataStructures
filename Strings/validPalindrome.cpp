/**
* Concept:
* Iterate from two sides
* Use alnum to remove non-alphanumeric chars
* https://leetcode.com/explore/interview/card/microsoft/30/array-and-strings/162/
*
* Input: s = "A man, a plan, a canal: Panama"
* Output: true
* Explanation: "amanaplanacanalpanama" is a palindrome.
**/
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length() == 0){ return true; }
        int start = 0; int n = s.length(); int end = n-1;
        while(start < n){
            if(isalnum(s[start]) == false){ start++; }
            else if(isalnum(s[end]) == false){ end--; }
            else if(tolower(s[start]) != tolower(s[end]) ){ return false; }
            else{ start++; end--; }
        }
        return true;
    }
};