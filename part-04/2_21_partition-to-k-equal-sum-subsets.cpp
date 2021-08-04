// Problem: https://leetcode.com/problems/partition-to-k-equal-sum-subsets/

// Backtracking solution
// O(k * (2 ^ n)) time, O(k + n) space

/*
Copied from https://leetcode.com/problems/partition-to-k-equal-sum-subsets/discuss/180014/Backtracking-Thinking-Process/578738

Time Complexity: What basically we are doing is, we are traversing the entire nums array for each subset
(once we are done with one subset, for the next subset we are starting again with index 0). So for each subset,
we are choosing the suitable elements from the nums array (basically iterate over nums and for each element either
use it or drop it, which is O(2^n) operation where n is the size of nums). We are doing the same for each subset.
Total subsets are k. So Time Complexity becomes O(k*(2^n)).

Space Complexity: Even though we are traversing the entire array for each subset, the height of the recursion tree
would still remain O(n) because we won't be calling the recursive function for already visited elements. Also, O(n)
for the visited array. So the Space Complexity becomes stack size + visited array = O(n)+O(n) = O(n).
*/

class Solution {
private:
    bool canSplit(
        vector<int>& nums,
        int curr_sum,
        int req_sum,
        int index_to_process,
        bool* taken,
        int k
    ) {
        if (k == 0) {
            return true;
        }

        if (curr_sum == req_sum) {
            return canSplit(
                nums,
                0,
                req_sum,
                0,
                taken,
                k - 1
            );
        }

        for (int i = index_to_process; i < nums.size(); i++) {
            if (!taken[i] && curr_sum + nums[i] <= req_sum) {
                taken[i] = true;
                if (canSplit(
                    nums,
                    curr_sum + nums[i],
                    req_sum,
                    i + 1,  // not (index_to_process + 1) !!!
                    taken,
                    k
                )) {
                    return true;
                }
                taken[i] = false;
            }
        }

        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if (k == 1) {
            return true;
        }

        int len = nums.size();
        if (k > len) {
            return false;
        }

        int total_sum = 0;
        for (int i = 0; i < len; i++) {
            total_sum = total_sum + nums[i];
        }

        if (total_sum % k != 0) {
            return false;
        }
        int req_sum = total_sum / k;

        bool taken[len];
        for (int i = 0; i < len; i++) {
            taken[i] = false;
        }

        return canSplit(
            nums,
            0,
            req_sum,
            0,
            taken,
            k
        );
    }
};