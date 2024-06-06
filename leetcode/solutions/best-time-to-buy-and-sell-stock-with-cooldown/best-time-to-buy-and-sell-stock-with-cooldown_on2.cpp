// Problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/submissions/

// O(n * n) time, O(n) space solution

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len < 2) {
            // cannot complete even a single transaction
            return 0;
        }
        
        // dp[i][0] stores the max profit that can be made till `i`, if NO stock was sold
        // on `i`
        // dp[i][1] stores the max profit that can be made till `i` if SOME stock was sold
        // on `i`
        int dp[len][2];

        // base cases
        dp[0][0] = 0;
        dp[0][1] = 0;
        dp[1][0] = 0;
        dp[1][1] = max(0, prices[1] - prices[0]);

        for (int i = 2; i < len; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            
            // sell stock at current price, and find max profit considering
            // all previous buying positions
            dp[i][1] = 0;
            for (int j = 0; j <= i - 2; j++) {
                dp[i][1] = max(dp[i][1], dp[j][0] + prices[i] - prices[j + 1]);
            }
            // special case for j = -1 (dp[j][0] does not exist)
            dp[i][1] = max(dp[i][1], prices[i] - prices[0]);
        }
        
        // the answer does not depend on if stock was sold
        // on last day or not
        return max(dp[len - 1][0], dp[len - 1][1]);
    }
};