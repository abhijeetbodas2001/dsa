// Problem: https://leetcode.com/problems/missing-number/

// O(n) time, O(1) space
// Using bit manipulation
// Identity: x^x = 0
// Identity: x^0 = x
// Because we're given that elements of `nums` lie in [0, n], if we XOR all
// indices of `nums` (that is, 0 to (n-1)) and all elements of `nums` (all
// of 0 to n except one) with `n`, only the missing number will remain.

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
		int xor_value = len;

		for (int i = 0; i < len; i++) {
			xor_value = xor_value ^ i ^ nums[i];
		}
		
		return xor_value;
    }
};
