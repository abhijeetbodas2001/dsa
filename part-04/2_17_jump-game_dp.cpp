// Problem: https://leetcode.com/problems/jump-game/

// DP solution
// O(n) space, O(m * n) time where m is the maximum element in nums

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();

        // dp[i] stores if the last index can be reached from `i`
        vector<bool> dp(len, false);

        // base case
        dp[len - 1] = true;

        for (int i = len - 2; i >= 0; i--) {
            int max_jump = nums[i];
            for (int j = 1; j <= max_jump && j + i <= len - 1; j++) {
                dp[i] = dp[i] || dp[i + j];
                if (dp[i] == true) {
                    break;
                }
            }
        }

        return dp[0];
    }
};