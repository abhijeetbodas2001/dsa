// Problem: https://leetcode.com/problems/minimum-depth-of-binary-tree/

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
    bool isLeaf(TreeNode* root) {
        assert(root != NULL);
        return root -> left == NULL && root -> right == NULL;
    }
public:
    int minDepth(TreeNode* root) {
        // Note: minDepth of tree is not always min of minDepths of the left and right
        // subtrees. Think why?
        if (root == NULL) {
            return 0;
        }

        if (isLeaf(root)) {
            return 1;
        }

        if (root -> left == NULL) {
            return 1 + minDepth(root -> right);
        } else if (root -> right == NULL) {
            return 1 + minDepth(root -> left);
        } else {
            return 1 + min(
                minDepth(root -> left),
                minDepth(root -> right)
            );
        }
    }
};