// Count & Say problem Leetcode https://leetcode.com/problems/count-and-say/

class Solution {
public:
    string countAndSay(int n) {
        //Specify your string for solution
        string ans;
        ans += "1";
        for(int i=1;i< n;i++){
            string buffer;
            // Iterate the previous string to get the next one
            for(int j=0 ; j < ans.length(); j++){
                int count = 1;
                //Handle the count of the value
                while(j+1 < ans.length() && ans[j] == ans[j+1]){ count++; j++; }
                buffer.push_back(count+'0');
                buffer += ans[j];
            }
            ans = buffer;
        } 
        return ans;
    }
};
