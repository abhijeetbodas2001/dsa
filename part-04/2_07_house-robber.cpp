// Problem: https://leetcode.com/problems/house-robber/

// See solution https://leetcode.com/problems/house-robber/discuss/156523/From-good-to-great.-How-to-approach-most-of-DP-problems.

/*
Important.

`dp[i]` here stands for the max money that can be robbed till the `i`th house.
How that money is robbed is irrelevant for the definition of `dp`. The `i`th house may
or may not have been robbed in the maxima.

But for the proof, let's see.
When will the `i`th house need to be robbed to get `dp[i]`?
    -> Only when dp[i - 2] + nums[i] > dp[i - 1] holds
    
        But what if dp[i - 1] does not rob `i - 1`?
        Shouldn't we definitely rob `i` in dp[i] then?
            Well, then its like `i - 1` didn't exist at all, and hence,
                dp[i - 1] == dp[i - 2]
            Hence,
                dp[i - 2] + nums[i] > dp[i - 1]

            So, to determine whether dp[i] should rob the `i`th house,
                "dp[i - 1] does not rob `i - 1`"
            is a subset of the condition,
                `dp[i - 2] + nums[i] > dp[i - 1]`


        But what if `i - 1` was robbed in dp[i - 1] and nums[i - 1] > nums[i]?
        Shouldn't dp[i] definitely rob `i` and do
            `dp[i] = dp[i - 1] - nums[i -1] + nums[i]`?
        Essentially, cleverly sacrifice the `i - 1`th house?
            Not required.
            If `i - 1` was robbed in dp[i - 1],
            then definitely,
                dp[i - 2] >= dp[i - 1] - nums[i - 1]
            This is beacuse if `i - 1` was robbed in dp[i - 1], then `i - 2`
            must definitely not have been robbed in dp[i - 1]. But dp[i - 2] has
            no such constraint on `i - 2`.

            Now that we know that
                dp[i - 2] >= dp[i - 1] - nums[i - 1],
            it follows that
                dp[i - 2] + nums[i] >= dp[i - 1] - nums[i - 1] + nums[i]
            
            So, to determine whether dp[i] should rob the `i`th house,
                "`i - 1` was robbed in dp[i - 1] and nums[i - 1] > nums[i]"
            is **also** a subset of the condition,
                `dp[i - 2] + nums[i] > dp[i - 1]`
            


We've thus proved that `dp[i - 2] + nums[i] > dp[i - 1]` is a necessary and sufficient
condition for dp[i] to rob `i`th house

But `dp` (the variable) does not bother about whether the `i`th house was
robbed, so just assign dp[i] to max(dp[i - 2] + nums[i] > dp[i - 1])

It also follows that we don't need to store whether dp[j] robs `j` or not,
because just the value of dp[j] is sufficient to calculate all the next dp's
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        int dp[len];
        for (int i = 0; i < len; i++) {
            dp[i] = 0;
        }

        // Base case
        dp[0] = nums[0];
        if (len == 1) {
            return nums[0];
        }
        // Another base case
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < len; i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }

        return dp[len - 1];

        // The above solution is O(n) time and O(n) space
        // It can be made O(1) space by using to variabled to
        // just store dp[i - 1] and dp[i - 2] at each iteration
    }
};