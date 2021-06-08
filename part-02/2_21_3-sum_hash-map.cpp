// Problem: https://leetcode.com/problems/3sum/

// DOES NOT WORK

/*
In this problem, two types of "duplication" can occur.

dup-1. We have found a triplet of indices (ind1, ind2, ind3), and have:
       el1 = nums[ind1],
       el2 = nums[ind2] and
       el3 = nums[ind3], with
       el1, el2, el3 adding up to target.
       If we now insert some permutation of the elements ((el2, el2, el3) for example)
       in the answer, that is bad.

dup-2. We have found (ind1, ind2, ind3) such that el1, el2, el3 (as defined above) add up to
       target. If there is also a some ind4 such that ind3 != ind4 and nums[ind3] = nums[ind4],
       then we don't want to insert (el1, el2, el3) twice into the answer because of this.
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int len = nums.size();
        if (len < 3) {
            // Empty array
            return ans;
        }

        // Map elements to a list of indices on which they occur
        unordered_map<int, vector<int>> val_to_indices;
        for (int i = 0; i < len - 2; i++) {
            if (val_to_indices.find(nums[i]) == val_to_indices.end()) {
                vector<int> vect{i};
                val_to_indices[nums[i]] = vect;
            } else {
                val_to_indices[nums[i]].push_back(i);
            }
        }

        for (int x = 0; x < len; x++) {
            for (int y = x + 1; y < len - 1; y++) {
                int partial_target = 0 - nums[x] - nums[y];

                if (val_to_indices.find(partial_target) != val_to_indices.end()) {
                    vector<int> indices = val_to_indices[partial_target];

                    // OK, so now we have `indices` as a list of indices on which `partial_target` occurs.
                    // Find some index to the right of y, so avoid duplicate triplets
                    for (int i = 0; i < indices.size(); i++) {
                        int z = indices[i];
                        if (z > y) {
                            // `z > y` prevents dup-1
                            vector<int> vect{nums[x], nums[y], nums[z]};
                            ans.push_back(vect);

                            // No duplicates for "z", so break if found
                            // This prevents dup-2
                            break;
                        }
                        
                    }
                }
            }
        }

        return ans;
    }
};