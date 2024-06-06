// Problem: https://leetcode.com/problems/sort-colors/

// O(n) time (one pass), O(1) extra space
// Two pointers

// This solution tries to minimize the number of swaps. One could
// write a much simplier (but still O(n) one pass) solution if
// it's OK to do a bunch of useless swaps. (Like swapping 0 with 0,
// or 2 with 2 etc)

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        int left = 0;
        int right = len - 1;
        int i = 0;

        while (true) {
            if (i > right) {
                // ^^^ Not `i >= right`, since we've provisioned for all elements starting
                // from `right + 1` (not `right`) to be `2`.
                break;
            }

            assert(0 <= nums[i] && nums[i] <= 2);

            int j = 2;
            while (j--) {
                // Why run this codeblock twice?
                // We may, for each `i`, in the worst case, need to do two swaps.
                // For example, say initially, nums[i] is 2. We then swap the 2 with something
                // given by `right`, say 0.
                // Now, we cannot leave this zero as is and move forward, because there may be a
                // `1` before `i`, so at the end array may not be sorted.
                // So, run the check again. Now, `0` will get swapped with something returned by
                // `left`, and this something must be `1`, because we've already put all the 2's
                // before `i` in the correct place, and the inner while loop ensures it cannot
                // be a `0` either.

                // If either of `left` or `right` from above return a `1`, we move on to the next `i`,
                // to avoid some unnecessary swaps.
                if (nums[i] == 1) {
                    continue;
                } else if (nums[i] == 2) {
                    while (nums[right] == 2 && right > i) {
                        right--;
                    }
                    swap(nums[i], nums[right]);
                } else if (nums[i] == 0) {
                    while (nums[left] == 0 && left < i) {
                        left++;
                    }
                    swap(nums[i], nums[left]);
                }
            }

            i++;
        }
    }
};