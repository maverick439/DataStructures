/**
 * Given an integer n, return true if it is a power of three. Otherwise, return false.
 * An integer n is a power of three, if there exists an integer x such that n == 3x.
 * 
 * Input: n = 27    Output: true
 * Input: n = 45    Output: false
 * 
 * Follow up: Could you solve it without loops/recursion?
 * */

// Basic Approach
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 1){ return true; }
        int i = 3; 
        while(i <= n){
            if(i == n){
                return true;
            }
            i = i*3;
        }
        return false;
    }
};

// Optimized Approach
// It finds the largest power of 3 less than INT_MAX first, and then checks if it is divisible by n. 
// log(INT_MAX)/log(3) equals to log3(INT_MAX)

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        int t = pow(3,(int)(log(INT_MAX)/log(3)));
        return (t%n == 0);
    }
};