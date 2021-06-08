// Problem: https://leetcode.com/problems/3sum/

// O(n^2log(n)) time, O(1) space
// Modifies the input
// Binary search method
// Be careful with uniqueness constraint

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int len = nums.size();
        if (len < 3) {
            // Empty array
            return ans;
        }

        sort(nums.begin(), nums.end());
        for (int x = 0; x < len - 2;) { // fix variable "x'"
            for (int y = x + 1; y < len - 1;) { // fix variable "y"
                // Now search for "z" with binary search
                int left = y + 1, right = len - 1, mid;
                int target = -nums[x] - nums[y];
                int z = -1;
                bool found = false;
                while (left <= right) {
                    mid = (left + right) / 2;
                    if (nums[mid] == target) {
                        found = true;
                        z = mid;
                        break;
                    } else if (nums[mid] > target) {
                        right = mid - 1;
                    } else if (nums[mid] < target) {
                        left = mid + 1;
                    }
                }

                if (found) {
                    vector<int> triplet{nums[x], nums[y], nums[z]};
                    ans.push_back(triplet);
                }

                // For each "x", only unique (y, z) pair should be put in answer
                // This loop will run at least once, so no need to put `y++` in the for loop
                int y_curr = y;
                while (y < len && nums[y] == nums[y_curr]) {
                    y++;
                }
            }

            // Answer should not have duplicate triplets
            // This loop will run at least once, so no need to put `x++` in the for loop
            int x_curr = x;
            while (x < len && nums[x] == nums[x_curr]) {
                x++;
            }
        }

        return ans;
    }
};