// Problem: https://leetcode.com/problems/longest-increasing-subsequence/

// O(n^2) time, O(n) space
// Solution https://leetcode.com/problems/longest-increasing-subsequence/discuss/74836/My-easy-to-understand-O(n2)-solution-using-DP-with-video-explanation

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        
        // dp[i] = length of longest subsequence ending at `i`
        int dp[len];
        for (int i = 0; i < len; i++) {
            dp[i] = 1;
        }

        for (int i = 1; i < len; i++) {

            // Bottom-up DP
            for (int j = 0; i < i; j++) {

                if (nums[j] < nums[i]) {
                    // We can extend the subsequence ending at `j` with `i`
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        int ans = 0; 
        for (int i = 0; i < len; i++) {
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};