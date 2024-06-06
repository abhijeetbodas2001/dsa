// Problem: https://leetcode.com/problems/target-sum/

// O(2^n) time, O(1) space solution
// Given n <= 20 => 2^n <= 10^6
// Recursion

class Solution {
private:
    void dfs(vector<int>& nums, int* count, int previous_sum, int index, int target) {
        // `count` stores the number of paths we've found
        // `previous_sum` stores the sum calculated upto the previous call stack
        // `index` is the index to be processed in this call

        if (index == nums.size()) {
            if (previous_sum == target) {
                *count = *count + 1;
            }
            return;
        }

        dfs(
            nums,
            count,
            previous_sum + nums[index],
            index + 1,
            target
        );

        dfs(
            nums,
            count,
            previous_sum - nums[index],
            index + 1,
            target
        );
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int count = 0;
        dfs(nums, &count, 0, 0, target);
        return count;
    }
};