// Problem: https://leetcode.com/problems/coin-change/

// Bottom-up, iterative DP
// O(n) time, O(n) space (where n is the "amount")

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // `dp[i]` = fewest coins required to get amount `i`
        int dp[amount + 1];

        // Initialize
        for (int i = 0; i <= amount; i++) {
            dp[i] = INT_MAX;
        }

        // Base case
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            // Note: iterating over `coins` is O(1), because given coins.length <= 12
            for (int j = 0; j < coins.size(); j++) {
                int denomination = coins[j];

                if (denomination > i) {
                    continue;
                }

                if (dp[i - denomination] == INT_MAX) {
                    // There isn't a way to get an amount of `i - denomination`
                    // Handling this case also prevents integer overflow later on
                    continue;
                }

                dp[i] = min(dp[i], dp[i - denomination] + 1);
            }
        }

        if (dp[amount] == INT_MAX) {
            // `amount` cannot be made up
            return -1;
        }

        return dp[amount];
    }
};