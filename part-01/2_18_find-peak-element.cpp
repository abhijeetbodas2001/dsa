// Problem: https://leetcode.com/problems/find-peak-element/

// O(log(n)) time, O(1) extra space
// Modified binary search.

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
		int left = 0;
		int right = len - 1;
		int mid;
		
		if (len == 1) {
			return 0;
		}
		
		while (true) {
			mid = (left + right) / 2;
			
			if (mid == 0) {
				if (left == 0 && right == 0) {
					assert(nums[0] > nums[1]);
					return 0;
				} else {
					assert(left == 0 && right == 1);
					return (nums[0] > nums[1]? 0 : 1);
				}
			}
			
			if (mid == len - 1) {
				assert(right == len - 1 && left == len - 1);
				assert(nums[len - 2] < nums[len - 1]);
				return len - 1;
			}
			
			// Note: Given no two consequetive elements are equal.
			if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1]) {
				return mid;
			} else if (nums[mid - 1] < nums[mid] && nums[mid] < nums[mid + 1]) {
				left = mid + 1;
			} else if (nums[mid - 1] > nums[mid] && nums[mid] > nums[mid + 1]) {
				right = mid - 1;
			} else {
				assert(nums[mid - 1] > nums[mid] && nums[mid] < nums[mid + 1]);
				// Both halves will have at least one peak. Arbitrarily select the right half.
				left = mid + 1;
			}
		}
    }
};