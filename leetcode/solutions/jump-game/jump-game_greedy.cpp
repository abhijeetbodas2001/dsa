// Problem: https://leetcode.com/problems/jump-game/

// Greedy solution
// see the DP solution first

// this utilizes the property of the problem that, if there is a non-reachable
// j, then all i > j must also be non-reachable
//
// Proof:
// Suppose j is NR, and j + 1 is R. Then, suppose one of the ways j + 1 can be reached
// by is jumping from k with a jump length x.
// Because j is assumed to be not reachable, k < j.
// But notice -- a jump from k with jump length x - 1 is also perfectly valid,
// and that would end at j, which contradicts the assumption that j is not reachable
// 

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();

        // `reach` stores the inex of the farthest element which we have
        // determined to be reachable
        int reach = 0;

        for (int i = 0; i < len; i++) {
            if (i > reach) {
                // `i` isn't reachable, so none of the elements after `i` are
                // reachable
                return false;
            }

            // update the reach
            reach = max(reach, i + nums[i]);
        }

        // all elements (indices) are reachable
        return true;
    }
};