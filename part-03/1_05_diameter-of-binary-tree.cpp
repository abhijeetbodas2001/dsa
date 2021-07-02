// Problem: https://leetcode.com/problems/diameter-of-binary-tree/

// Recursive DFS

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
    int maxDepthModified(TreeNode* root, int* diameter) {
        // Returns the depth below the given node
        if (root == NULL) {
            // Diameter does not include the edge from leaf node to NULL,
            // so return -1 to adjust the overcalculation done earlier.
            return -1;
        }

        int left_depth = maxDepthModified(root -> left, diameter);
        int right_depth = maxDepthModified(root -> right, diameter);

        *diameter = max(*diameter, left_depth + right_depth + 2);

        return max(left_depth, right_depth) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        // We can't use "the two deepest nodes" and add them up, because
        // could have some common ancestor

        int diameter = -1;
        maxDepthModified(root, &diameter);
        return diameter;
    }
};
