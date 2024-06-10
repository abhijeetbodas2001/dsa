// Problem: https://leetcode.com/problems/partition-equal-subset-sum/

// Bruteforce: use recursion to generate binary tree, with a choice for each
// element "take" or "don't take"
// then check if a path sum is sum / 2

// This solution is O(n * sum) time and )(n * sum) space, where
// `sum` is the sum of all elements in array

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // note: making subsets with equal sums is equivalent to forming
        // one subset with sum of elements equal to half of sum of all
        // elements in array
        int total_sum = 0;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            total_sum = total_sum + nums[i];
        }

        if (total_sum % 2 == 1) {
            // IMPORTANT! The further code may not return the correct answer for this
            // case
            return false;
        }

        int req_sum = total_sum / 2;

        // dp[i][s] is true if it is possible to get a sum of `s` using elements
        // upto `i`
        bool dp[len][total_sum + 1];
        for (int i = 0; i < len; i++) {
            for (int j = 0; j <= total_sum; j++) {
                dp[i][j] = false;
            }
        }

        // base case
        dp[0][0] = true;
        dp[0][nums[0]] = true;

        for (int i = 1; i < len; i++) {
            for (int s = 0; s <= total_sum; s++) {

                // this is the "don't include the `i`th element in the subset case"
                dp[i][s] = dp[i - 1][s];

                // index out of bounds guard
                if (s - nums[i] >= 0) {
                    // this is the case where we include the `i`th element in the subset
                    dp[i][s] = dp[i][s] || dp[i - 1][s - nums[i]];
                }
            }
        }

        return dp[len - 1][req_sum];
    }
};