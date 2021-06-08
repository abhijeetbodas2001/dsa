// Problem: https://leetcode.com/problems/missing-number/

// O(n) time, O(1) space
// Using sums

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
		int expected_sum = len * (len + 1) / 2;
		int actual_sum = 0;
		
		for (int i = 0; i < len; i++) {
			actual_sum = actual_sum + nums[i];
		}
		
		int missing_number = expected_sum - actual_sum;
		return missing_number;
    }
};
