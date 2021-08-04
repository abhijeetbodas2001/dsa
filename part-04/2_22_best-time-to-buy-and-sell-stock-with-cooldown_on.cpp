// Problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/submissions/

// O(n) time, O(n) space solution

// See the O(n * n) time solution first
// In the inner loop in that solution, we travel over all previous indeces to find a maximum
// The inner loop can be avoided if we introduce a variable to store this value and update
// in on each iteration of the outer loop

// Note: because we only read the `i - 1` and `i - 2` th values in each iteration,
// this solution can further be optimised to O(1) space


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len < 2) {
            // cannot complete even a single transaction
            return 0;
        }
        
        // dp[i][0] stores the max profit that can be made till `i`, if NO stock was sold
        // no `i`
        // dp[i][1] stores the max profit that can be made till `i` if SOME stock was sold
        // on `i`
        int dp[len][2];

        // base cases
        dp[0][0] = 0;
        dp[0][1] = 0;
        dp[1][0] = 0;
        dp[1][1] = max(0, prices[1] - prices[0]);

        // `maxbuy` Keeps track of **maximum** value of `dp[i - 2][0] - prices[i - 1]`
        // this will be used to calculate `dp[i][1]` (Sell stock in `i`th day)
        int maxbuy = -1 * prices[0];

        // Note the initial value of `maxbuy`. It simulates buying the stock on
        // the i = 0 and selling it on i = i

        for (int i = 2; i < len; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);

            maxbuy = max(maxbuy, dp[i - 2][0] - prices[i - 1]);
            
            dp[i][1] = prices[i] + maxbuy;
        }
        
        return max(dp[len - 1][0], dp[len - 1][1]);
    }
};