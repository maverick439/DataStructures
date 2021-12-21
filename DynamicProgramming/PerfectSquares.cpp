/**
 * Given an integer n, return the least number of perfect square numbers that sum to n.
 * A perfect square is an integer that is the square of an integer; in other words, 
 * it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.
 * 
 * Input: n = 12    Output: 3
 * Explanation: 12 = 4 + 4 + 4.
 * 
 * */

//M1: Recursive Approach
int numSquares(int n) {
    int ans = n;
    for(int i = 1; i*i<= n; i++){
        ans = min(ans, numSquares(n-i*i)+1);
    }
    return ans;
}

//M2: DP O(N* N^.5) 
int numSquares(int n) {
    int dp[n+1];
    dp[0] = 0;
    
    for(int i=1; i<= n; i++){
        dp[i] = i; // Worst case scenario
        for(int j=1; j*j <= i; j++){
            int sq = j*j;
            dp[i] = min(dp[i], 1+dp[i-sq]);
        }
    }
    return dp[n];
}

//M3: Legendre's 3 Square Theorem
int numSquares(int n) {
    int sq = sqrt(n);
    if(sq*sq == n) // Perfect Square case
        return 1;
    
    while(n%4 == 0) // Removing the 4^a term
        n = n/4;
    
    if(n%8 == 7) // Check if no is of the form 8b+7 
        return 4;
    
    for(int i=1; i*i <= n; i++){
        int base = sqrt(n - i*i);
        if(base*base == n-i*i) // Check single breakpoint for two squares
            return 2;
    }
    return 3;
}