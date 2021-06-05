/**
 * Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. 
 * Return the answer in any order.
 * A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
 * 
 * Input: digits = "23"
 * Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
 * 
 * 
 * */


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int n = digits.size(); vector<string> ans;
        if(n == 0){ return ans; }
        vector<string> words {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        deque<string>q;
        q.push_back("");
        
        for(char digit : digits){
            int d = digit - '0';
            for(int i = q.size(); i > 0; i--){
                string token = q.front();
                q.pop_front();
                for(char ch : words[d]){
                    q.push_back(token + ch);
                }
            }
        }
        return vector<string>(q.begin(),q.end());
    }
};