// Problem: https://leetcode.com/problems/partition-equal-subset-sum/

// See the high space solution first
// In that solution, to calculate `dp[i][s]`, we only utilized `dp[i - 1][...]`
// this gives a clue that we can reduce the space complexity by one dimension,
// and store only stuff about the **previous iteration**

// So the space complexity is reduced to O(n), but the time complexity
// remains O(n * sum)

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total_sum = 0;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            total_sum = total_sum + nums[i];
        }

        if (total_sum % 2 == 1) {
            return false;
        }

        int req_sum = total_sum / 2;

        // dp[s] is true if it is possible to get a sum of `s` using elements
        // upto the **previous index**
        bool dp[total_sum + 1];
        for (int s = 0; s <= total_sum; s++) {
            dp[s] = false;
        }

        // base case
        dp[0] = true;
        dp[nums[0]] = true;

        // this will store data for the current iteration
        int dp_new[total_sum + 1];

        for (int i = 1; i < len; i++) {
            // calculate `dp_new` for this iteration
            for (int s = 0; s <= total_sum; s++) {
                dp_new[s] = dp[s];

                // index out of bounds guard
                if (s - nums[i] >= 0) {
                    dp_new[s] = dp_new[s] || dp[s - nums[i]];
                }
            }
            
            // update `dp` to `dp_new` for the next iteration of outer loop
            for (int j = 0; j <= total_sum; j++) {
                dp[j] = dp_new[j];
            }
        }

        return dp[req_sum];
    }
};