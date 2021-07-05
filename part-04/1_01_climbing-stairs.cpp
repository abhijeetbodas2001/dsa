// Problem: https://leetcode.com/problems/climbing-stairs/

// o(n) time, O(n) space
// simple dynamic programming

class Solution {
public:
    int climbStairs(int n) {
        // `dp[i]` stores the number of ways to reach step `i`
        int dp[n + 1];

        // 0 steps does not make sense. Store whatever.
        dp[0] = -1;

        if (n < 3) {
            // See below comments
            // Answer for 1 is 1 and for 2 is 2
            return n;
        }

        // There's only one way to reach step 1 -- "one step" * 1
        dp[1] = 1;

        // There are 2 ways to reach step 2 -- "one step" * 2 and "two steps" * 1
        dp[2] = 2;

        for (int i = 3; i <= n; i++) {
            // There are two options for the last method used to reach step `i`
            // Either you take a "one step" from step `i - 1` or you take a "two steps"
            // from step `i - 2`
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];

        // The series actually ends up being a Fibonacci sequence
    }
};