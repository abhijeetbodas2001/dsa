// Problem: https://leetcode.com/problems/number-of-longest-increasing-subsequence/

// O(n*n) time, O(n) space solution
// This uses the same idea of https://leetcode.com/problems/longest-increasing-subsequence/

// TODO: Implement the fancy Binary Search for this too

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int len = nums.size();

        // dp[i][0] stores length of the LIS ending at `i`
        // dp[i][1] stores the number of LIS'es ending at `i` with the maximal length
        vector<vector<int>> dp(len);

        for (int i = 0; i < len; i++) {
            dp[i].resize(2);
            // base cases: LIS is the `i` element
            dp[i][0] = 1;
            dp[i][1] = 1;
        }

        // bottom UP DP
        for (int i = 1; i < len; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if (dp[j][0] + 1 > dp[i][0]) {
                        // Starting a-new
                        // There are dp[j][1] sequences which we extend by the `i`th element
                        dp[i][0] = dp[j][0] + 1;
                        dp[i][1] = dp[j][1];    // NOTE: Not dp[i][1] = 1
                    } else if (dp[j][0] + 1 == dp[i][0]) {
                        // We've already found some sequence with this length
                        // just update the counter
                        dp[i][1] = dp[i][1] + dp[j][1]; // NOTE: Not dp[i][1]++
                    }
                }
            }
        }

        // find length of LIS
        int lis_len = dp[0][0];
        for (int i = 0; i < len; i++) {
            lis_len = max(lis_len, dp[i][0]);
        }

        // find number of LIS
        int ans = 0;
        for (int i = 0; i < len; i++) {
            if (dp[i][0] == lis_len) {
                ans = ans + dp[i][1];
            }
        }

        return ans;
    }
};