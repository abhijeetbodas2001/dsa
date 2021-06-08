// Problem: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

// This solution does not work.
// Question is crappy.

class Solution {
private:
	bool isRightOfInflectionPoint(vector<int>& nums, int index, int len) {
		assert(index != 0 && index != len - 1);
		
		if (nums[index] < nums[0] || nums[index] > nums[len - 1]) {
			return true;
		}
		
		if (nums[index] > nums[0] || nums[index] < nums[len - 1]) {
			return false;
		}
		
		assert(nums[index] == nums[0] && nums[index] == nums[len - 1]);
		
		// Linearly check if element lies in the right
		int i = index;
		int elem = nums[index];
		while (i < len) {
			if (nums[i] != elem) {
				return false;
			}
			i++;
		}
		return true;
	}
public:
    bool search(vector<int>& nums, int target) {
        int len = nums.size();
		int left = 0;
		int right = len - 1;
		int mid;
		
		if (len == 1) {
			return nums[0] == target;
		}
		
		if (nums[0] == target || nums[len - 1] == target) {
			return true;
		}
		
		while (left <= right) {
			mid = (left + right) / 2;
			
			if (mid == 0) {
				return nums[0] == target || nums[1] == target;
			}
			
			if (mid == len - 1) {
				return nums[len - 1] == target;
			}
			
			if (nums[mid] == target) {
				return true;
			} else if (target < nums[mid]) {
				if (isRightOfInflectionPoint(nums, mid, len)) {
					left = mid - 1;
				} else {
					if (nums[0] <= target) {
						right = mid - 1;
					} else {
						left = mid + 1;
					}
				}
			} else if (nums[mid] < target) {
				if (isRightOfInflectionPoint(nums, mid, len)) {
					if (nums[len - 1] >= target) {
						right = mid + 1;
					} else {
						left = mid - 1;
					}
				} else {
					right = mid + 1;
				}
			}
		}
		
		return false;
    }
};