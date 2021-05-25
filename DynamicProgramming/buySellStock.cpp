/**
 * You are given an array prices where prices[i] is the price of a given stock on the ith day.
 * You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
 * Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
 * 
 * Input: prices = [7,1,5,3,6,4]
 * Output: 5
 * Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
 * Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
 * 
 * 
 * https://leetcode.com/explore/interview/card/microsoft/49/dynamic-programming/186/
 * 
 * */


// Buy before sell & only one cuycle of buying & selling 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(); int max_profit = 0;
        int current_profit = 0; int min_price = INT_MAX;
        for(int i = 0;i < n;i++){
            min_price = min(min_price, prices[i]);
            max_profit = max(max_profit, prices[i] - min_price);
        }
        return max_profit;
    }
};

/**
prices = [7,1,5,3,6,4]
MIN PRICE :: 7 MAX PROFIT :: 0
MIN PRICE :: 1 MAX PROFIT :: 0
MIN PRICE :: 1 MAX PROFIT :: 4
MIN PRICE :: 1 MAX PROFIT :: 4
MIN PRICE :: 1 MAX PROFIT :: 5
MIN PRICE :: 1 MAX PROFIT :: 5
**/



// When buying && selling multiple times is allowed
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(); int max_profit = 0;
        int current_profit = 0; 
        for(int i = 1;i < n;i++){
            current_profit = max(current_profit, current_profit+prices[i]-prices[i-1]);
            max_profit = max(max_profit, current_profit);
        }
        return max_profit;
    }
};

/**
prices = [7,1,5,3,6,4]
Current Profit 0 Max Profit 0
Current Profit 4 Max Profit 4
Current Profit 4 Max Profit 4
Current Profit 7 Max Profit 7
Current Profit 7 Max Profit 7
**/