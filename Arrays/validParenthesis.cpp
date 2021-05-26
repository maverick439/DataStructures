/**
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * An input string is valid if:
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 * Input: s = "()[]{}"
 * Output: true
 * https://leetcode.com/explore/interview/card/microsoft/30/array-and-strings/179/discuss/9222/My-0ms-c++-solution-using-stack
 * 
 * 
 * */

class Solution {
public:
    bool isValid(string s) {
        stack<char>stack;
        for(char c : s){
            if(c == '(' || c == '{' || c == '['){ stack.push(c); }
            else{
                if(stack.empty()){ return false; }
                else if(c == ')' && stack.top() != '('){ return false; }
                else if(c == '}' && stack.top() != '{'){ return false; }
                else if(c == ']' && stack.top() != '['){ return false; }
                stack.pop();
            }
        }
        if(stack.empty()){ return true; }
        return false;
    }
};


