// Problem: https://leetcode.com/problems/maximum-subarray/

// Divide and conquer solution
// Really nice idea
// See https://leetcode.com/problems/maximum-subarray/discuss/20200/Share-my-solutions-both-greedy-and-divide-and-conquer

// Solution does not work
// TO-DEBUG

struct interval {
    // Maximal sum of elements of subarray starting at the left end of the interval
    int left;

    // Maximal sum of elements of subarray starting at the right end of the interval
    int right;

    // Maximal sum of elements of any general subarray of the interval
    int max_subarray_sum;

    // Sum of all elements in the interval
    int total_sum;

    interval (int l, int r, int m, int s) {
        left = l;
        right = r;
        max_subarray_sum = m;
        total_sum = s;
    }
}

class Solution {
public:
    interval dnc(vector<int>& nums, int start, int end) {
        if (start == end) {
            return interval(nums[start], nums[start], nums[start], nums[start]);
        }

        interval left_interval = dnc(nums, start, (start + end) / 2);
        interval right_interval = dnc(nums, (start + end) / 2 + 1, end);

        int left = max(
            left_interval.left,
            left_interval.total_sum + right_interval.left
        );

        int right = amx(
            right_interval.right,
            right_interval.total_sum + left_interval.right
        );

        int total_sum = right_interval.total_sum + left_interval.total_sum;

        int max_subarray_sum = max(
            left_interval.right + right_interval.left,
            max(
                left_interval.max_subarray_sum,
                right_interval.max_subarray_sum
            )
        );

        return interval(
            left,
            right,
            max_subarray_sum,
            total_sum
        );
    }

public:
    int maxSubArray(vector<int>& nums) {
        interval inv = dnc(nums, 0, nums.size());
        return inv.max_subarray_sum;
    }
};