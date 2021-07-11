// Problem: https://leetcode.com/problems/kth-smallest-element-in-a-bst/

// In-order traversal
// O(h + k) time, O(N) space

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> dfs;
        int num = k;

        TreeNode* curr = root;
        while (dfs.size() > 0 || curr != NULL) {
            while (curr != NULL) {
                dfs.push(curr);
                curr = curr -> left;
            }

            curr = dfs.top();
            dfs.pop();

            num--;
            if (num == 0) {
                // We've processed k nodes
                // So the current one must be the one we need to find
                return curr -> val;
            }
            curr = curr -> right;
        }

        // Control should not reach here
        assert(false);
        return -1;
    }
};