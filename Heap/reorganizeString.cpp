/**
 * 
 * Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
 * Return any possible rearrangement of s or return "" if not possible.
 * 
 * Example 1:
 * Input: s = "aab"     Output: "aba"
 * 
 * Example 2:
 * Input: s = "aaab"       Output: ""
 * 
 * https://leetcode.com/problems/reorganize-string/
 * */

class Solution {
public:
    string reorganizeString(string s) {
        string res = "";
        unordered_map<char, int> umap;
        priority_queue<pair<int, char>> pq;
        
        for(char c : s)
            umap[c] += 1;
        
        for(auto m : umap)
            pq.push(make_pair(m.second, m.first));
        
        while(pq.size() > 1) {
            auto top1 = pq.top();   pq.pop();
            auto top2 = pq.top();   pq.pop();
            
            res += top1.second;     top1.first--;
            res += top2.second;     top2.first--;
            
            if(top1.first > 0){ pq.push(top1); }
            if(top2.first > 0){ pq.push(top2); }
        }
            
        if(!pq.empty()){
            if(pq.top().first > 1){ return ""; }
            else{
                res += pq.top().second;
                pq.pop();
            }
        }
        return res;
    }
};