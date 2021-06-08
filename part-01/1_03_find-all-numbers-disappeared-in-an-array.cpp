// Problem: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

// A trivial solution would be to use hash maps, which would run in
// O(n) time, O(n) space.

// This solution runs in O(1) space (excluding the output array) and
// O(n) time.
// NOTE: This solution will also modify the input!

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len = nums.size();
		vector<int> missing_nums;
		int index;
		for (int i = 0; i < len; i++) {
			index = (nums[i] - 1) % len;	// Not nums[i] % len
			if (index < 0) {
				// Ensure that 0 <= index <= len - 1
				index = index + len;
			}

			// `index` is now the value of ith element in the original array.
			// "Mark" that we have seen this value, by making the nums[nums[i] - 1]th
			// value negative.
			nums[index] = nums[index] - len;
		}
		
		for (int i = 0; i < len; i++) {
			if (nums[i] > 0) {
				// This element is positive, so the index must be missing.
				missing_nums.push_back(i + 1);
			}
		}

		return missing_nums;
    }
};
