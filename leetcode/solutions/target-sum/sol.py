class Solution:
    def findTargetSumWays(self, nums: list[int], target: int) -> int:
        assert sum(nums) <= 1000  # This is given
        if target > 1000 or target < -1000:
            return 0

        n = len(nums)

        # dp[i][j] = number of ways to reach a sum of `j` using elements starting
        # from and including `i`
        # Recursive relation: dp[i][j] = dp[i+1][j-nums[i]] + dp[i][j+nums[i]]
        # The sum can go from -1000 to +1000
        buffer = 2000  # buffer + actual sum = index in the array
        dp = [[0 for _ in range(-2000, 2000)] for _ in range(n)]

        # Base case
        # Don't set it to one, instead increment one, to the handle
        # the case when nums[n-1] == 0
        dp[n - 1][buffer + nums[n - 1]] += 1  # sum = nums[n-1]
        dp[n - 1][buffer - nums[n - 1]] += 1  # sum = -nums[n-1]

        for idx in range(n - 2, -1, -1):
            for cummulative in range(-1000, 1001):
                sum1 = cummulative - nums[idx]
                sum2 = cummulative + nums[idx]

                # We use only idx and idx+1 at one time. So this array does not
                # need to be 2D -- two 1D arrays will also work (curr and prev)
                dp[idx][buffer + sum1] += dp[idx + 1][buffer + cummulative]
                dp[idx][buffer + sum2] += dp[idx + 1][buffer + cummulative]

        return dp[0][buffer + target]


answers = [
    Solution().findTargetSumWays([1, 2, 3], 6),
    Solution().findTargetSumWays([1, 2, 3], 4),
    Solution().findTargetSumWays([1, 2, 3], 0),
    Solution().findTargetSumWays([1, 2, 3], 8),
    Solution().findTargetSumWays([1, 2, 3], 8),
    Solution().findTargetSumWays([1, 0], 1),
]

for a in answers:
    print(a)
