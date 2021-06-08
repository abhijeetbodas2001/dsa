// Problem: https://leetcode.com/problems/contains-duplicate/

// O(n) time, O(n) space
// This solution uses an early return method, but we can also always insert
// the element in the loop and compare sizes of the array and set at the end.

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int len = nums.size();
		set<int> elems;
		for (int i = 0; i < len; i++) {
			int num = nums[i];
			if (elems.find(num) != elems.end()) {
				return true;
			}
			
			elems.insert(num);
		}
		
		return false;
    }
};
