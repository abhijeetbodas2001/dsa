// Problem: https://leetcode.com/problems/maximum-subarray/

// O(n) time, O(n) space
// Classic DP

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();

        // `dp[i]` is the sum of elements of that subarray which ends at `i`
        // and has the maximum sum
        int dp[len];

        // Base case
        dp[0] = nums[0];

        for (int i = 1; i < len; i++) {
            if (dp[i - 1] < 0) {
                // max sum ending at `i - 1` is negative
                // Clearly, no subarray ending at `i - 1` can have a positive sum,
                // because the maximum sum itself is negative. So, start anew.
                dp[i] = nums[i];
            } else {
                // Otherwise, continue the subarray ending at `i - 1`
                dp[i] = dp[i - 1] + nums[i];
            }
        }

        int max_sum = INT_MIN;
        for (int i = 0; i < len; i++) {
            max_sum = max(max_sum, dp[i]);
        }

        return max_sum;
    }
};