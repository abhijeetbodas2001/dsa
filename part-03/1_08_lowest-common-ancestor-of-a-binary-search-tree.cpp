// Problem: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

// Recursive BST
// O(h) time complexity

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
    TreeNode* searchTree(TreeNode* root, int p_val, int q_val) {
        assert(p_val < q_val);

        // A node is it's own ancestor too, so don't use strict inequalities
        if (p_val <= root -> val && root -> val <= q_val) {
            return root;
        } else if (root -> val < p_val) {
            return searchTree(root -> right, p_val, q_val);
        } else {
            assert(q_val < root -> val);
            return searchTree(root -> left, p_val, q_val);
        }
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p -> val > q -> val) {
            swap(p, q);
        }
        // Find the node such that `p -> val < node -> val && node -> val < q -> val`
        // Because it's a BST, there will be only one such node, assuming p and q exist
        // in the tree
        return searchTree(root, p -> val, q -> val);
    }
};
