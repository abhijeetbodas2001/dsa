// Problem: https://leetcode.com/problems/two-sum/

// O(n) time, O(n) space two pass solution.
// One can also d this in a single pass, because (a + b) == (b + a) holds!

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        // Value to index mapping
        unordered_map<int, int> index_of;
        for (int i = 0; i < len; i++) {
            index_of[nums[i]] = i;
        }

        vector<int> ans;
        for (int i = 0; i < len; i++) {
            int to_find = target - nums[i];
            if (index_of.find(to_find) != index_of.end()) {
                if (index_of[to_find] != i) {
                    ans.push_back(i);
                    ans.push_back(index_of[to_find]);
                    return ans;
                }
            }
        }

        // Control never reaches here as per given constraint.
        return ans;

    }
};