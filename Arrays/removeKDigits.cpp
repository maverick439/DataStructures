/**
 * Given string num representing a non-negative integer num, and an integer k, 
 * return the smallest possible integer after removing k digits from num.
 * Example 1:Input: num = "1432219", k = 3
 * Output: "1219"
 * Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
 * 
 * Edge Case 1:
 * Input: num = "12345", k = 2
 * Output: "123"
 * 
 * Edge Case 2:
 * Input: num = "100200", k = 1
 * Output: "200"
 * 
 * Edge Case 3:
 * Input: num = "41", k = 2
 * Output: "0"
 * */

// Approach 1
// Whenever the next val is less than the prev value, then removing the previous value will 
// generate the number with lowest value
// If all negative slopes are erased that means that its a leading sequence, hence remove from the end
class Solution {
public:
    string removeKdigits(string num, int k) {
        while(k > 0){
            int n = num.size();
            int i = 0;
            while(i+1<n && num[i] <= num[i+1]){ i++; }
            // Erase when num[i] > num[i+1] or delete from the last if it's sorted in ascending
            num.erase(i,1);
            k--;
        }       
        //Remove Leading 0's
        int s = 0;
        while(num[s] == '0' && s < num.size()){ s++; }
        num.erase(0,s);
        return num.size() == 0 ? "0" : num;
    }
};

// Approach 2
// Use a Stack(coz negative slopes) & pop out numbers with negative slopes
