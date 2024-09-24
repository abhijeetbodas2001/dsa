// Problem: https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

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
    vector<vector<int>> ans;

    void pushLevel(queue<TreeNode*>& level) {
        vector<int> current_level_vector;

        int width = level.size();

        for (int i = 0; i < width; i++) {
            TreeNode* node = level.front();
            level.pop();
            assert(node != NULL);

            current_level_vector.push_back(node -> val);

            if (node -> left != NULL) {
                level.push(node -> left);
            }

            if (node -> right != NULL) {
                level.push(node -> right);
            }
        }

        // Push the next level before the current one
        // This gives the bottom-up order using backtracking
        if (level.size() > 0) {
            pushLevel(level);
        }

        ans.push_back(current_level_vector);
    }
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        // A trivial solution is to go top -> down and then reverse the
        // resulting array, but we avoid that.

        // This solution ...

        if (root == NULL) {
            return ans;
        }

        queue<TreeNode*> level;
        level.push(root);
        pushLevel(level);

        return ans;
    }
};