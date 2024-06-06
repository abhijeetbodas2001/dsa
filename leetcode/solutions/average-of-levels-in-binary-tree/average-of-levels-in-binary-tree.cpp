// Problem: https://leetcode.com/problems/average-of-levels-in-binary-tree/

// BFS

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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if (root == NULL) {
            return ans;
        }

        queue<TreeNode*> bfs;
        bfs.push(root);
        
        while (!bfs.empty()) {
            // One while loop iteration here corresponds to one level of tree, not one node
            double sum = 0;
            int num_nodes_in_current_level = bfs.size();
            for (int i = 0; i < num_nodes_in_current_level; i++) {
                TreeNode* node = bfs.front();
                bfs.pop();

                sum = sum + node -> val;

                if (node -> left != NULL) {
                    bfs.push(node -> left);
                }
                if (node -> right != NULL) {
                    bfs.push(node -> right);
                }
            }
            ans.push_back(sum / num_nodes_in_current_level);
        }

        return ans;
    }
};