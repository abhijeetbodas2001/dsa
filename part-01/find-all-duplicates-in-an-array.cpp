// Problem: https://leetcode.com/problems/find-all-duplicates-in-an-array/

// O(n) time, O(1) extra space
// Modifies the input.
// This uses subtraction to "mark" the numbers.
// See https://leetcode.com/problems/find-all-duplicates-in-an-array/discuss/92395/C%2B%2B-beats-98
// for a solution which uses negation for marking.

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
		vector<int> ans;
		int num_orig;

		for (int i = 0; i < n; i++) {
			num_orig = nums[i];
			
			while (!(1 <= num_orig && num_orig <= n)) {
				// This loop will execute a maximum of 2 times, so
				// does not add to the time complexity.
				// One could also use some modulo methods to calculate
				// `num_orig`.
				num_orig = num_orig + n;
			}
			
			// Store that we saw `nums[i]` (`num_orig`, actually) by deducting
			// `n` from `nums[nums[i] - 1]`
			nums[num_orig - 1] = nums[num_orig - 1] - n;
		}
		
		for (int i = 0; i < n; i++) {
			if (1 <= nums[i] + 2 * n && nums[i] + 2 * n <= n) {
				ans.push_back(i + 1);
			}
		}
		
		return ans;
    }
};