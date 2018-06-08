/*
Leetcode task from https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

Plan

Keep track of min_price (minimum value in the array) and 
max_profit (maximum difference between current price and min_price)

Pseudo code

init min_price
init max_profit

go thru prices:
    if prices[i] < min_price:
        update min_price
    else if prices[i] - min_price > max_profit:
        update max_profit

*/

class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        if (!prices.size()) {
            return 0;
        }
        
        int max_profit = 0;
        int min_price = INT_MAX;
        
        for (int i = 0; i < prices.size(); ++i) {
            if (prices[i] < min_price) min_price = prices[i];
            else if (prices[i] - min_price > max_profit) max_profit = prices[i] - min_price;
        }
        
        return max_profit;
    }
};
