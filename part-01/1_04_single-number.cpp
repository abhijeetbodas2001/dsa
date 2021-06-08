// Problem: https://leetcode.com/problems/single-number/

// O(n) time, O(1) space
// The usual XOR trick.

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int len = nums.size();
		int xor_value = 0;
		
		for (int i = 0; i < len; i++) {
			xor_value = xor_value ^ nums[i];
		}
		
		// The numbers appearing twice would have vanished, and only the
		// single number would have remained.
		return xor_value;
    }
};