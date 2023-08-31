// Problem: https://leetcode.com/problems/peak-index-in-a-mountain-array/

// Trivial solution -> linear search.
// This solution uses binary search.
// O(log(n)) time.

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int len = arr.size();
		int left = 0;
		int right = len - 1;
		int mid;
		
		// Given mountain array, so we will always find an answer.
		while (true) {
			mid = (left + right) / 2;
			
			if (mid == 0) {
				// Will happen when left = right = 0 (not possible because given mountin array)
				// or when left = 0 and right = 1, which means `right` is the answer.
				return mid + 1;
			}
			
			if (mid == len - 1) {
				// Similar reasoning as above.
				return (len - 2);
			}
			
			// `mid` is somewhere in between, so compare neighboring values.
			if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) {
				return mid;
			} else if (arr[mid - 1] > arr[mid]) {
				right = mid - 1;
			} else if (arr[mid] < arr[mid + 1]) {
				left = mid + 1;
			}
		}
    }
};