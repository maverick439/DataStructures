/**
 * https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/
 * 
 * 
 * 
 * */

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size(); long sum = 0;
        // sum the array and take it's modulo with k to remove all the full circles
        for(auto i : chalk){ sum += i; }
        k = k%sum;
        
        // now we start from 0th student and keep of going ahead
        // until a student has shortage of chalks
        int i = 0;
        while(i < n){
            if(k < chalk[i]){ return i; }
            k = k - chalk[i];
            i++;
        }
        return 0;
    }
};

/**
Problem:
With the naive approach the continous circling of subtraction will create TLE as the numbers & circles are huge 

Concept:
Trick 1: k can be too big, so skip full circles by only considering k % sum(chalk).
Trick 2: sum(chalk) array can exceed INT_MAX, use long (0l) to accumulate.
**/