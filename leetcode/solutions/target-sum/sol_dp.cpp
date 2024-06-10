// Problem: https://leetcode.com/problems/target-sum/

// 2D dp
// See the official solution for explaination
// This can be reduced to 1D further, because we only need the `i - 1` to calculate `i`
// (That doesn't change the complexity though)

// The solution heavily utilizes the constraint on the `sum_all`

class Solution {
private:
    int sum_all = 0;

    int index_from_sum(int sum) {
        // -sum_all -> 0
        // sum_all -> 2 * sum_all
        return sum + sum_all;
    }

    int sum_from_index(int index) {
        return index - sum_all;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            assert(nums[i] >= 0);   // Given. Otherwise, use `abs(nums[i])`
            sum_all = sum_all + abs(nums[i]);
        }

        // Given
        assert(len <= 20);
        assert(sum_all <= 1000);

        // `dp[i][j]` stores the number of paths ending at `i` with sum `sum_from_index(j)`
        int dp[len][sum_all * 2 + 1];

        // Initialize all to zero
        for (int i = 0; i < len; i++) {
            for (int j = 0; j <= sum_all * 2; j++) {
                dp[i][j] = 0;
            }
        }

        // Base case
        dp[0][index_from_sum(nums[0])]++;   // Note! Don't assign to 1 here. It will be wrong if the first element is zero
        dp[0][index_from_sum(-nums[0])]++;  // ----------""----------------

        for (int i = 1; i < len; i++) {
            for (int sum = -sum_all; sum <= sum_all; sum++) {
                // We can reach `sum` either by adding `nums[i]` to `sum - nums[i]`
                // or by subtracting `nums[i]` from `sum + nums[i]`

                int lower_index = index_from_sum(sum - nums[i]);
                int upper_index = index_from_sum(sum + nums[i]);
                
                // Take care of bounds
                if (lower_index >= 0) {
                    // Here, we'll add `nums[i]` to the lower sum
                    dp[i][index_from_sum(sum)] = dp[i][index_from_sum(sum)] + dp[i - 1][lower_index];
                }

                if (upper_index <= 2 * sum_all) {
                    // Here, we'll subtract `nums[i]` from the upper sum
                    dp[i][index_from_sum(sum)] = dp[i][index_from_sum(sum)] + dp[i - 1][upper_index];
                }
            }
        }

        if (target < -sum_all || target > sum_all) {
            return 0;
        }
        return dp[len - 1][index_from_sum(target)];
    }
};