// Problem: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

// O(log(n)) time, O(1) extra space.
// Binary search variant
// Be carefult with mid = 0 and mid = len - 1

class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
		
		int left = 0;
		int right = len - 1;
		int mid;
		
		if (len == 1) {
			// Edge case.
			return nums[0];
		}
		
		if (nums[0] < nums[len - 1]) {
			// This means the array isn't rotated (or is rotated multiple of `len` times)
			return nums[0];
		}
		
		while (true) {
			mid = (left + right) / 2;
			
			if (mid == 0) {
				// left = 0 and right = 0 is not possible -- that would mean the
				// isn't rotated, and we've already dealt with that case.
				assert(left == 0 && right == 1);
				return nums[1];
			}
			
			if (mid == len - 1) {
				assert(left == len - 1 && right == len - 1);
				return nums[len - 1];
			}
			
			// Note: Given that all elements are unique.
			if (nums[mid - 1] > nums[mid] && nums[mid] < nums[mid + 1]) {
				// Correct match.
				return nums[mid];
			} else {
				if (nums[0] > nums[mid] && nums[mid] < nums[len - 1]) {
					// `mid` is after the minimum element.
					right = mid - 1;
				} else if (nums[0] < nums[mid] && nums[mid] > nums[len - 1]) {
					// `mid` is before the minimum element.
					left = mid + 1;
				}
			}
		}
    }
};