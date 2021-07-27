// Problem: https://leetcode.com/problems/combination-sum-iv/

// recursive DP
// O(n) time, O(n) space (recursion stack and `dp` array are both O(n))

class Solution {
private:
    // dp[i] stores the number of ways to make a sum of i
    // dp[i] = -1 denotes "not calculated yet"
    vector<int> dp;

    int numWays(vector<int>& nums, int target) {
        if (target < 0) {
            return 0;
        }

        // use the memoized data and avoid calculating things if possible
        if (dp[target] != -1) {
            return dp[target];
        }

        int num_ways = 0;
        for (int i = 0; i < nums.size(); i++) {
            // one of the ways to form `target` is to select a `nums[i]`
            // and then form a `target - nums[i]`
            num_ways = num_ways + numWays(nums, target - nums[i]);
        }

        dp[target] = num_ways;
        return num_ways;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        dp.resize(target + 1, -1);

        // base case
        // there is exactly one way to get a 0 -- you select no coin
        dp[0] = 1;
    
        return numWays(nums, target);
    }
};