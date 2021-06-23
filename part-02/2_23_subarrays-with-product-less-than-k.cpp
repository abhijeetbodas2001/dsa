// Problem: https://leetcode.com/problems/subarray-product-less-than-k/

// O(n) time, O(1) space solution.
// Two pointers
// Time complexity if O(n), since we do no more than 2*n "steps", where
// each "step" moves forward one of `left` or `right` by one index.

// This solution depends crucially on the fact that the array elements are
// all positive **and** greater than 1

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int len = nums.size();
        int ans = 0;
        int left = 0;
        int right = 0;
        int prod = 1;

        for (; right < len; right++) {
            // For each `right`, we find the leftmost `left` such that the product of elements
            // in `nums` between `left` and `right` is less than `k`.

            // Then, for all `i` such that `left <= i <= right`, the subarray [i, right] is a "good"
            // subarray (meaning, product of elements is less than `k`), add the number of such `i`s
            // to `ans`.

            // The loop just incremented `right`, so update the product.
            prod = prod * nums[right];

            // Try to make the product is less than `k`
            while (left < right && prod >= k) {
                prod = prod / nums[left];
                left++;
            }

            if (left == right) {
                assert(prod == nums[right]);
                if (prod >= k) {
                    // We couldn't make the product less than `k`.
                    // There doesn't exist `left` such that the product `left` to `right` (both included)
                    // is less than `k`, so nothing to do here.
                    continue;
                } else {
                    // There's only a single "good" subarray.
                    ans++;
                }
            } else if (left < right) {
                assert(prod < k);

                // Add the number of subarrays.
                ans = ans + right - left + 1;
            }
        }

        // Note that, `prod` cannot overflow here. We're given `nums[i] < 1000`, and `prod`
        // can have the maximum value of max(nums[i]) * k, just before the inner while loop.

        return ans;
    }
};