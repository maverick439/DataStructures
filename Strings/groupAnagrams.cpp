/**
 * Given an array of strings strs, group the anagrams together. You can return the answer in any order.
 * An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
 * typically using all the original letters exactly once.
 * 
 * Input: strs = ["eat","tea","tan","ate","nat","bat"]
 * Output: [["bat"],["nat","tan"],["ate","eat","tea"]
 * https://leetcode.com/explore/interview/card/microsoft/30/array-and-strings/200/
 * */


/**
Approach 1: With Sorting

Sort each string and store it in a map
Compare with the sorted string

Time Complexity: O(MNLogM)
**/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mymap;
        int n = strs.size();
        string temp;
        for(int i=0; i<n; i++){
            temp = strs[i];
            sort(strs[i].begin(), strs[i].end());
            mymap[strs[i]].push_back(temp);
        }
        vector<vector<string>>result;
        for(auto i : mymap){
            result.push_back(i.second);
        }
        return result;
    }
};

/**
Approach 2: Without Sorting

Store the sequence of char occurence in a hash
If it exists already add it to that bucket

Time Complexity: O(M*N)
**/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char, int>, vector<string>> my_map;
        int n = strs.size();
        string temp;
        for(string s : strs){
            map<char, int> temp_map;
            vector<string> temp_my_list;
            for(int i=0; i<s.length(); i++){ ++temp_map[s[i]]; }
            auto it = my_map.find(temp_map);
            if(it != my_map.end()){
                it->second.push_back(s);
            }
            else{
                temp_my_list.push_back(s);
                my_map.insert({temp_map, temp_my_list});
            }
        }
        vector<vector<string>>result;
        for(auto it = my_map.begin(); it != my_map.end(); it++){
            result.push_back(it->second);
        }
        return result;
    }
};