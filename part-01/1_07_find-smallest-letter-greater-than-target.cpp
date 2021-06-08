// Problem: https://leetcode.com/problems/find-smallest-letter-greater-than-target/

// O(log(n)) time, no extra space.
// Variation of the binary search. Note the corner cases.

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int len = letters.size();
		int left = 0;
		int right = len - 1;
		int mid;
		
		if (target < letters[0]) {
			// Edge case.
			return letters[0];
		}
		
		// This loop should always return something, so let's make that obvious with `true`.
		while (true) {
			mid = (left + right) / 2;
			
			if (mid == len - 1) {
				// left = right = len - 1, hence, letters[len - 1] <= target
				// Wrapping case
				return letters[0];
			}

			assert(0 <= mid && mid <len);
			
			if (letters[mid] <= target && target < letters[mid + 1]) {
				return letters[mid + 1];
			} else if (target < letters[mid]) {
				right = mid - 1;
			} else if (letters[mid + 1] <= target) {
				left = mid + 1;
			}
		}
    }
};