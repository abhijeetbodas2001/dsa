// Problem: https://leetcode.com/problems/same-tree/

// DFS, recursive
// O(n) time (each node visited once)
// Space -> O(n) worst case, O(log(n)) best case. Depends on height of tree

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) {
            return true;
        } else if (p != NULL && q != NULL) {
            return (
                (p -> val == q -> val) &&
                isSameTree(p -> left, q -> left) &&
                isSameTree(p -> right, q -> right)
            );
        } else {
            return false;
        }
    }
};