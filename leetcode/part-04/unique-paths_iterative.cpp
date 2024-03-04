// Problem: https://leetcode.com/problems/unique-paths/

// O(m*n) time, O(m*n) space solution

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m);
        for (int i = 0; i < m; i++) {
            dp[i].resize(n, -1);
        }

        // base case
        dp[0][0] = 1;

        // more base cases; there is exactly one way to reach any cell in the first row
        // or any cell in the first column (first meaning, 0 indexed row/column)
        for (int i = 0; i < m; i++) {
            dp[i][0] = 1;
        }

        for (int j = 0; j < n; j++) {
            dp[0][j] = 1;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                // both i and j are greater than equal to 1, so the components
                // dp[i - 1][j] and dp[i][j - 1] are definitely valid
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};