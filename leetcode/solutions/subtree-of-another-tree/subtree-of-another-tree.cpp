// Problem: https://leetcode.com/problems/subtree-of-another-tree/

// This is a O(n^2) solution
// For a better(?) solution, see
// https://leetcode.com/problems/subtree-of-another-tree/discuss/102741/Python-Straightforward-with-Explanation-(O(ST)-and-O(S%2BT)-approaches)

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
    bool isSameTree(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL && t2 == NULL) {
            return true;
        } else if (t1 != NULL && t2 != NULL) {
            return (
                t1 -> val == t2 -> val &&
                isSameTree(t1 -> left, t2 -> left) &&
                isSameTree(t1 -> right, t2 -> right)
            );
        } else {
            // Only one of them is NULL
            return false;
        }
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL) {
            return subRoot == NULL;
        }

        return (
            isSameTree(root, subRoot) ||
            isSubtree(root -> left, subRoot) ||
            isSubtree(root -> right, subRoot)
        );
    }
};