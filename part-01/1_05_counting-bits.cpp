// Problem: https://leetcode.com/problems/counting-bits/

// O(n) time, O(1) space

class Solution {
public:
    vector<int> countBits(int n) {
		// DP relation
		// ans[i] = ans[i / 2] + i % 2
		// Essentially, split `i` into two parts, and add the number of ones
		// thes two parts.
		// The two parts are:
		// A. The last binary digit of `i`. The number of ones here is either
		// 0 or 1, and equal to i % 2.
		// B. Everything else. The number of ones here is ans[i >> 2], which is the
		// same as and[i / 2]
		
		vector<int> ans(n + 1, 0);
		ans[0] = 0;
		
		for (int i = 1; i <= n ;i++) {
			ans[i] = ans[i / 2] + (i % 2);
		}
		
		return ans;
    }
};