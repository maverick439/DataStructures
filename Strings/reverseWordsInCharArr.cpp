/**
 * Given a character array s, reverse the order of the words.
 * A word is defined as a sequence of non-space characters. The words in s will be separated by a single space.
 * Your code must solve the problem in-place, i.e. without allocating extra space.
 * 
 * Input: s = ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]
 * Output: ["b","l","u","e"," ","i","s"," ","s","k","y"," ","t","h","e"]
 * 
 * */


/*
Basic Algo
1. Reverse the entire char array
2. Reverse each word
*/

class Solution {
public:
    void reverseWords(vector<char>& s) {
        int n = s.size(); int blank = 0;
        int start = 0; int end = n-1;
        // Reverse the entire array
        reverse(s.begin(), s.end());
        // Reverse each word
        while(blank < n){
            // Reach the space
            while(blank < n && s[blank] != ' '){ blank++; }
            int index = blank-1;
            // Swap the word
            while(start < index){
                swap(s[start++], s[index--]);
            }
            // Move to next word
            blank = blank+1;
            start = blank;
            
        }
        
    }
};

// Better Approach - Same Complexity
class Solution {
public:
    void reverseWords(vector<char>& s) {
        int pos = 0;
        for(int i = 0; i < s.size(); i++){
            if(i == s.size()-1 || s[i+1] == ' '){
                reverse(s.begin()+pos, s.begin()+i+1);
                pos = i+2;
            }
        }
        reverse(s.begin(), s.end());
    }
};