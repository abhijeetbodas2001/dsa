// Problem: https://leetcode.com/problems/combination-sum-iv/

// iterative DP
// O(n) time, O(n) space


// In an iterative, bottom up solution, there's no need to have a value
// for "not calculated yet", precisely because it is bottom up

// NOTE: This resulted in integer overflow on LeetCode for some reason.
// needs to be debugged, but it may even be the case that Leetcode has
// a bad testcase

class Solution {
private:
public:
    int combinationSum4(vector<int>& nums, int target) {

        // Initialize everything to zero, because we're always adding things
        vector<int> dp(target + 1, 0);

        // base case
        // there is exactly one way to get a 0 -- you select no coin
        dp[0] = 1;

        for (int current_target = 1; current_target <= target; current_target++) {
            for (int i = 0; i < nums.size(); i++) {
                if (current_target - nums[i] >= 0) {
                    dp[current_target] = dp[current_target] + dp[current_target - nums[i]];
                }
            }
        }
    
        return dp[target];
    }
};