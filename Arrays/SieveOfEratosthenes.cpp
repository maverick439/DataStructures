/**
Given an integer n, return the number of prime numbers that are strictly less than n.

**/

class Solution {
public:
    int countPrimes(int n) {
        if(n == 0 || n == 1)
            return 0;
        vector<bool> prime(n, true);
        prime[0] = false, prime[1] = false;
        for (int i = 0; i < sqrt(n); ++i) {
            if (prime[i]) {
                for (int j = i*i; j < n; j += i) {
                    prime[j] = false;
                }    
            }    
        }
        return count(prime.begin(), prime.end(), true);
    }
};
