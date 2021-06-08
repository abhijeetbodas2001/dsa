// Problem: https://leetcode.com/problems/3sum-closest/

// O(n*n) time, O(1) extra space, modified input
// Two pointers

class Solution {
private:
    void updateSum(int current_sum, int* old_sum, int target) {
        if (abs(current_sum - target) > abs(*old_sum - target)) {
            return;
        } else {
            *old_sum = current_sum;
        }
    }
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();

        if (len < 3) {
            throw invalid_argument("Array length is less than 3");
        }

        // Array should be sorted for two pointers to work correctly
        // Mutates the input
        // O(n*log(n)) here is overshadowed by the O(n*n) coming up next
        sort(nums.begin(), nums.end());

        // Random initialization from elements in the array
        // Using INT_MAX will overflow in the abs(old_sum - target) above if target is -ve
        int ans = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < len - 2; i++) {
            int j = i + 1;
            int k = len - 1;

            while (j < k) { // NOTE: Not j <= k, since we want distinct elements
                int current_sum = nums[i] + nums[j] + nums[k];
                updateSum(current_sum, &ans, target);

                if (current_sum == target) {
                    return target;
                } else if (current_sum < target) {
                    j++;
                } else if (current_sum > target) {
                    k--;
                }
            }
        }

        return ans;
    }
};