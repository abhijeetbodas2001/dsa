// Problem: https://leetcode.com/problems/majority-element/

// Boyer-more algorithm.

// Problem: https://leetcode.com/problems/majority-element/solution/

// Boyer-Moore voting algorithm (fancy!)
// O(n) time, O(1) extra space.
// See https://leetcode.com/problems/majority-element/solution/ for detailed solution.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
		int len = nums.size();
        int current_majority_candidate = nums[0];
		int current_count = 1;
		
		for (int i = 1; i < len; i++) {
			if (current_count == 0) {
				// Reset.

				// If `current_majority_candidate` is actually the global majority
				// number, we will never reach this point.

				// If it is not the global majority number, and we delete (forget) the
				// prefix up-to now, the majority number of the resulting suffix will
				// still be the same as the actual global majority number, because the number
				// of "deleted" elements which are equal to the global major are less
				// than or equal to half of the total deleted elements.

				current_count = 1;	// Not 0 :)
				current_majority_candidate = nums[i];
				continue;
			}

			if (current_majority_candidate == nums[i]) {
				current_count++;
			} else {
				current_count--;
			}
		}
		
		return current_majority_candidate;
    }
};