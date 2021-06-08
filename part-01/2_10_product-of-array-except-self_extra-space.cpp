// Problem: https://leetcode.com/problems/product-of-array-except-self/

// O(n) time, O(n) extra space.
// Use prefix and suffix array to store products.
// In the end, ans[i] = prefix_product[i - 1] * suffix_product[i + 1]

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
		
		vector<int> prefix_product(len, 0);
		prefix_product[0] = nums[0];

		vector<int> suffix_product(len, 0);
		suffix_product[len - 1] = nums[len - 1];
		
		for (int i = 1; i < len; i++) {
			prefix_product[i] = prefix_product[i - 1] * nums[i];
		}
		
		// Given len >= 2
		for (int i = len - 2; i >= 0; i--) {
			suffix_product[i] = suffix_product[i + 1] * nums[i];
		}
		
		vector<int> ans(len, 0);
		ans[0] = suffix_product[1];
		ans[len - 1] = prefix_product[len - 2];
		for (int i = 1; i < len - 1; i++) {
			ans[i] = prefix_product[i - 1] * suffix_product[i + 1];
		}
		
		return ans;
    }
};