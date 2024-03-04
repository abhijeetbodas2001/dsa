// Problem: https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

// O(h) space, O(n) time
// Kinda BFS, but with recursion

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

    void pushLevel(queue<TreeNode*>& level_to_process) {
        queue<int> next_level;
        vector<int> current_level_vector;

        int width = level_to_process.size()

        for (int i = 0; i < width; i++) {
            TreeNode* node = level_to_process.front();
            level_to_process.pop();
            assert(node != NULL);

            current_level_vector.push_back(node -> val);

            if (node -> left != NULL) {
                next_level.push(node -> left);
            }

            if (node -> right != NULL) {
                next_level.push(node -> right);
            }
        }

        // Push the next level before the current one
        // This gives the bottom-up order using backtracking
        if (next_level.size() > 0) {
            pushLevel(next_level);
        }

        ans.push_back(current_level_vector);
    }
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        // A trivial solution is to go top -> down and then reverse the
        // resulting array, but we avoid that.

        // This solution uses recursion stacks to get the reverse order

        if (root == NULL) {
            return ans;
        }

        queue<TreeNode*> level;
        level.push(root);
        pushLevel(level);

        return ans;
    }
};