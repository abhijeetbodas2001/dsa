// Problem: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

// Slightly modified BFS
// This DOES NOT actually traverse the tree in a zigzag fashion
// but uses array indices to do the magic

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) {
            return ans;
        }

        queue<TreeNode*> bfs;
        bfs.push(root);
        bool ltr = true;    // ltr = "left to right"

        while (bfs.size() > 0) {
            int level_width = bfs.size();
            vector<int> level(level_width, 0);

            for (int i = 0; i < level_width; i++) {
                TreeNode* node = bfs.front();
                bfs.pop();

                // process node
                if (ltr) {
                    level[i] = node -> val;
                } else {
                    level[level_width -1 - i] = node -> val;
                }

                if (node -> left != NULL) {
                    bfs.push(node -> left);
                }

                if (node -> right != NULL) {
                    bfs.push(node -> right);
                }
            }

            ans.push_back(level);
            ltr = !ltr;
        }

        return ans;
    }
};