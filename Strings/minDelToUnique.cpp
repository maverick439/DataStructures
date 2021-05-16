/*
Minimum Deletions to Make Character Frequencies Unique
https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/
*/
#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
    int minDeletions(string s) {
        int count[26] = {}; 
        int result = 0;
        unordered_map<int,int> tracker;
        for(char i : s){
            count[i-'a']++;
        }
        for(int i=0;i<26;i++){
            if(count[i] == 0){
                continue;
            }
            else if(tracker.find(count[i]) != tracker.end()){
                result++;
                count[i]--;
                i--;
            }
            else{
                tracker[count[i]] = 1;
            }
        }
        return result;
    }
};



