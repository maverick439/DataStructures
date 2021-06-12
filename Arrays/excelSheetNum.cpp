/**
 * Input: columnTitle = "A"
 * Output: 1
 * 
 * Input: columnTitle = "AB"
 * Output: 28
 * 
 * Input: columnTitle = "ZY"
 * Output: 701
 * */

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.size(); int num = 0; int index = 0;
        for(int i=n-1; i>=0; i--){
            if(index == 0){ num += (int)columnTitle[i]-64; }
            else{
                num += pow(26,index)*((int)columnTitle[i]-64);    
            }
            index++;
        }
        return num;
    }
};