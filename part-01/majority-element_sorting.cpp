// Problem: https://leetcode.com/problems/majority-element/

// Sorting method. O(nlog(n)) time.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
		int len = nums.size();
        sort(nums.begin(), nums.end());

		int current_elem = nums[0];
		int max_elem = nums[0];
		int current_count = 0;
		int max_count = 0;
		
		for (int i = 0; i < len; i++) {
			if (nums[i] == current_elem) {
				current_count++;
			} else {
				if (current_count > max_count) {
					max_count = current_count;
					max_elem = current_elem;
				}

				current_count = 1;
				current_elem = nums[i];
			}
		}
		
		// Process the last element.
		if (current_count > max_count) {
			max_count = current_count;
			max_elem = current_elem;
		}
		
		return max_elem;
		
		// Above solution is pretty generic. It will find the number that occurs
		// the max number of time.
		// If that number occurs more than n/2 times, just return arr[n/2]
    }
};