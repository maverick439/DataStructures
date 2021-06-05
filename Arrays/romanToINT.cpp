/**
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000


 * */

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>map = {{'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}};
        int sum = 0;
        for(int i=0; i<s.size()-1; i++){
            if(map[s[i]] < map[s[i+1]]){ sum -= map[s[i]]; }
            else{ sum+= map[s[i]]; }
        }
        sum += map[s[s.size()-1]];
        return sum;
    }
};