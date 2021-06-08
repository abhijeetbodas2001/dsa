// Problem: https://leetcode.com/problems/squares-of-a-sorted-array/

// O(n) time, O(n) space, two pointers

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int len = nums.size();
        vector<int> copy;
        for (int i = 0; i < len; i++) {
            copy.push_back(nums[i]);
        }

        if (copy[0] < 0) {
            int first_negative_elem = 0;
            int last_negative_elem = 0;
            for (int i = 0; i < len; i++) {
                if (copy[i] < 0) {
                    last_negative_elem = i;
                    // Make these elements +ve, because we will anyways square them later.
                    copy[i] = copy[i] * -1;
                } else {
                    break;
                }
            }

            // Reverse the negative prefix subarray
            for (int i = first_negative_elem; i <= last_negative_elem / 2; i++) {
                int temp = copy[i];
                copy[i] = copy[last_negative_elem - i];
                copy[last_negative_elem - i] = temp;
            }

            // Now, we have two parts of the original array: [0, last_negative_elem] and [last_negative_elem + 1, len - 1]
            // Both these parts are sorted, and we need to merge them.
            int i = 0, j = last_negative_elem + 1;  // Pointers for these two subarrays
            int k = 0;  // Pointer for the original array
            while (i <= last_negative_elem && j < len) {
                if (copy[i] >= copy[j]) {
                    nums[k] = copy[j];
                    j++;
                } else if (copy[i] < copy[j]) {
                    nums[k] = copy[i];
                    i++;
                }

                k++;
            }

            while (i <= last_negative_elem) {
                nums[k] = copy[i];
                i++;
                k++;
            }

            while (j < len) {
                nums[k] = copy[j];
                j++;
                k++;
            }
        }

        // Square all elements
        for (int i = 0; i < len; i++) {
            nums[i] = nums[i] * nums[i];
        }

        return nums;

        // Instead of reversing the negative subarray prefix, one could also have a pointer going
        // backwards in the "merge" step
    }
};