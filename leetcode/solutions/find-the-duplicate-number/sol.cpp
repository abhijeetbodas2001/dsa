// Problem: https://leetcode.com/problems/find-the-duplicate-number/

// Tort/Hare algorithm
// See https://leetcode.com/problems/find-the-duplicate-number/solution/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Tort and hare start at `nums[0]`, not `0`
        int tort = nums[0], hare = nums[0];
        do {
            tort = nums[tort];
            hare = nums[nums[hare]];
        } while (tort != hare);

        tort = nums[0];
        while (tort != hare) {
            tort = nums[tort];
            hare = nums[hare];
        }

        return tort;
    }
};