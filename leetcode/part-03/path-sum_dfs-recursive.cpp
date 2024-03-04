// Problem: https://leetcode.com/problems/path-sum/

// DFS, recursive
// O(n) time
// O(log(n)) to O(n) stack space

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
private:
    bool isLeaf(TreeNode* node) {
        assert(node != NULL);
        return node -> left == NULL && node -> right == NULL;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL) {
            // Only for first (entry) stack. We don't call with NULL recursively.
            return false;
        }

        if (isLeaf(root)) {
            if (targetSum == root -> val) {
                return true;
            } else {
                return false;
            }
        }

        assert(root -> left != NULL || root -> right != NULL);
        bool has_path_sum = false;
        if (root -> left != NULL) {
            has_path_sum = has_path_sum || hasPathSum(root -> left, targetSum - root -> val);
        }
        if (root -> right != NULL) {
            has_path_sum = has_path_sum || hasPathSum(root -> right, targetSum - root -> val);
        }
        return has_path_sum;
    }
};
