// Problem: https://leetcode.com/problems/house-robber-ii/

/*
O(n) time, O(n) space
Be careful with indices


From the problem hint:
Since House[1] and House[n] are adjacent, they cannot be robbed together.
Therefore, the problem becomes to rob either House[1] to House[n-1] or House[2] to House[n],
depending on which choice offers more money. Now the problem has degenerated to the "House Robber"
problem, which has already been solved.
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();

        // Trivial cases
        if (len == 1) {
            return nums[0];
        }
        if (len == 2) {
            return max(nums[0], nums[1]);
        }
        if (len == 3) {
            return max(nums[0], max(nums[1], nums[2]));
        }

        int ans = 0;

        int dp0[len];   // 0 to len - 2
        int dp1[len];   // 1 to len - 1
        for (int i = ; i < len; i++) {
            dp0[i] = 0;
            dp1[i] = 0;
        }

        dp0[0] = nums[0];
        dp0[1] = max(nums[0], nums[1]);
        for (int i = 0; i < len - 1; i++) {
            dp0[i] = max(dp0[i - 2] + nums[i], dp0[i - 1]);
            ans = max(ans, dp0[i]);
        }

        dp1[1] = nums[1];
        dp1[2] = max(nums[1], nums[2]);
        for (int i = 1; i < len; i++) {
            dp1[i] = max(dp1[i - 2] + nums[i], dp1[i - 1]);
            ans = max(ans, dp1[i]);
        }

        return ans;
    }
};