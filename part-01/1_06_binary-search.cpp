// Problem: https://leetcode.com/problems/binary-search/

// O(log(n)) time, no extra space
// Vanilla binary search implementation, iterative

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
		int left = 0;
		int right = len - 1;
		int mid;
		
		while (left <= right) {
			mid = (left + right) / 2;

			if (nums[mid] == target) {
				return mid;
			} else if (nums[mid] < target) {
				left = mid + 1;
			} else if (nums[mid] > target) {
				right = mid - 1;
			}
		}
		
		return -1;
    }
};