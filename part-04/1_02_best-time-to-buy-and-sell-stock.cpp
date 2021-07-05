// Problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

// Not DP!!! (simple logic)
// O(n) time, O(1) space

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;
        int max_profit = 0;
        int len = prices.size();

        for (int i = 0; i < len; i++) {
            // What we are actually doing is this: for every element, we are
            // calculating the difference between that element and the minimum
            // of all the values before that element and we are updating the
            // maximum profit if the difference thus found is greater than the
            // current maximum profit.
            min_price = min(min_price, prices[i]);
            max_profit = max(max_profit, prices[i] - min_price);
        }

        return max_profit;
    }
};