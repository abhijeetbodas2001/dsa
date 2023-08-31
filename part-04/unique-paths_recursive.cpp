// Problem: https://leetcode.com/problems/unique-paths/

// O(m * n) time and O(m * n) space recursive DP

class Solution {
private:
    // dp[i][j] stores number of ways to reach (m - 1, n - 1) from (i, j)
    // dp[i][j] = -1 stands for "not calculated yet"
    vector<vector<int>> dp;

    int numWays(int i, int j, int m, int n) {
        assert(0 <= i && 0 <= j);
        assert(i < m && j < n);

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int ans = 0;
        if (i + 1 < m) {
            ans = ans + numWays(i + 1, j, m , n);
        }

        if (j + 1 < n) {
            ans = ans + numWays(i, j + 1, m , n);
        }

        dp[i][j] = ans;
        return ans;
    }
public:
    int uniquePaths(int m, int n) {
        dp.resize(m);
        for (int i = 0; i < m; i++) {
            dp[i].resize(n, -1);
        }

        // Base case
        // there is exactly one way to reach (m - 1, n - 1) from (m - 1, n - 1)
        dp[m - 1][n - 1] = 1;

        return numWays(0, 0, m, n);
    }
};