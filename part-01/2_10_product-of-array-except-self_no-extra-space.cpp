// Problem: https://leetcode.com/problems/product-of-array-except-self/

// O(n) time, O(1) extra space.
// This is just a hacky version of the "extra-space" variant, which uses
// the input and the `ans` to store the prefix and suffix products!

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
		
		vector<int> ans(len, 0);	// This will store suffixes.
		
		// Copy the input into `ans`
		for (int i = 0; i < len; i++) {
			ans[i] = nums[i];
		}

		// Store preffix products in `nums`
		for (int i = 1; i < len; i++) {
			nums[i] = nums[i - 1] * nums[i];
		}
		
		// Store suffix products in `ans`
		for (int i = len - 2; i >= 0; i--) {
			ans[i] = ans[i + 1] * ans[i];
		}
		
		// Temporarily store `suff[1]`, so that we can later store it in
		// `ans[0]`, because `ans[1]` will be over-written later.
		int temp = ans[1];
		
		// Store the correct answers in `ans`. Note the direction of iteration,
		// to ensure any data which will be used in the future isn't overwritten
		// in the current iteration.
		for (int i = 1; i < len - 1; i++) {
			ans[i] = ans[i + 1] * nums[i - 1];
		}

		// `ans[0]` already contains the correct `ans[0]`, and has not been
		// overwritten in the loop above.

		ans[0] = temp;	// suff[1]
		ans[len - 1] = nums[len - 2];	// pref[len - 2]

		return ans;
    }
};