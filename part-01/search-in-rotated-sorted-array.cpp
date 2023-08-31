// Problem: https://leetcode.com/problems/search-in-rotated-sorted-array/

// O(log(n)) time, O(1) extra space
// Modified binary search.
// Note where to put <= and where < etc.
// If choosing a half segment that can include the target, use <= or >=
// If eliminating a half, use < or >

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
		int left = 0;
		int right = len - 1;
		int mid;
		
		if (len == 1) {
			return nums[0] == target ? 0 : -1;
		}
		
		while (left <= right) {
			mid = (left + right) / 2;
			
			if (nums[mid] == target) {
				return mid;
			} else if (target < nums[mid]) {
				if (nums[mid] <= nums[len - 1]) {
					// `mid` is to the right of the inflection point
					// All elements to the right of `mid` are bigger than `nums[mid]`
					right = mid - 1;
				} else {
					// `mid` is to the left of inflection point
					// 0 to `mid` is a sorted subarray
					if (nums[0] <= target) {
						// 0 to mid will contain `target`, if at all
						right = mid - 1;
					} else {
						// 0 to `mid` cannot contain `target`
						left = mid + 1;
					}
				}
			} else if (nums[mid] < target) {
				if (nums[0] <= nums[mid]) {
					// `mid` is to the left of inflection point
					// All elements to left of `mid` are smaller than `nums[mid]`
					left = mid + 1;
				} else {
					// `mid` is to the right of inflection point
					// `mid` to `len - 1` is a sorted subarray
					if (nums[len - 1] < target) {
						// `mid` to `len - 1` cannot contain `target`
						right = mid - 1;
					} else {
						// `mid` to `len - 1` will contain `target`, if at all
						left = mid + 1;
					}
				}
			}
		}
		
		return -1;
    }
};