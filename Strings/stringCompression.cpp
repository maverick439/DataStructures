/**
 * Given an array of characters chars, compress it using the following algorithm:
 * Begin with an empty string s. For each group of consecutive repeating characters in chars:
 * If the group's length is 1, append the character to s.
 * Otherwise, append the character followed by the group's length.
 * 
 * The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.
 * After you are done modifying the input array, return the new length of the array.
 * You must write an algorithm that uses only constant extra space.
 * 
 * Input: chars = ["a","a","b","b","c","c","c"]
 * Output: ["a","2","b","2","c","3"]
 * 
 * */

class Solution {
public:
    int compress(vector<char>& chars) {        
        int n = chars.size();
        if(n < 2){ return n; }
        
        int i = 0; int j = 0;
        
        while(i < n){
            chars[j] = chars[i];
            int count = 0;
            
            while(i < n && chars[i] == chars[j]){
                count++;
                i++;
            }    
            
            if(count == 1){
                j++;
            }
            else{
                string str = to_string(count);
                for(auto c : str)
                    chars[++j] = c;
                j++;
            }
        }
        return j;
    }
};