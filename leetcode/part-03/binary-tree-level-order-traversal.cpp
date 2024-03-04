// Problem: https://leetcode.com/problems/binary-tree-level-order-traversal/

// ez
// Plain BFS

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) {
            return ans;
        }

        queue<TreeNode*> bfs;
        bfs.push(root);

        while (bfs.size() > 0) {
            int level_width = bfs.size();
            vector<int> level_vector;

            for (int i = 0; i < level_width; i++) {
                TreeNode* node = bfs.front();
                bfs.pop();

                // process node
                level_vector.push_back(node -> val);

                if (node -> left != NULL) {
                    bfs.push(node -> left);
                }

                if (node -> right != NULL) {
                    bfs.push(node -> right);
                }
            }

            ans.push_back(level_vector);
        }

        return ans;
    }
};