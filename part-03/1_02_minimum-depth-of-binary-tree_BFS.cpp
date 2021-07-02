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
        if (root == NULL) {
            return 0;
        }

        int current_level = 1;
        queue<TreeNode*> bfs;
        bfs.push(root);

        while (bfs.size() != 0) {
            int current_breadth = bfs.size();
            for (int i = 0; i < current_breadth; i++) {
                TreeNode *node = bfs.front();
                bfs.pop();

                if (isLeaf(node)) {
                    // All the node remaining to be processed must have level >= current_level,
                    // because we're processing node level-by-level.
                    return current_level;
                }

                if (node -> left != NULL) {
                    bfs.push(node -> left);
                }

                if (node -> right != NULL) {
                    bfs.push(node -> right);
                }
            }

            current_level++;
        }

        // Control will never reach here.
        assert(false);
        return -1;
    }
};