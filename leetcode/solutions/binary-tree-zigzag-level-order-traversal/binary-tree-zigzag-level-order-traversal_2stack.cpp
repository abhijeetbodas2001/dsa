// Problem: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

// This solution actually traverses the tree in a zigzag manner

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

        stack<TreeNode*> to_process;
        stack<TreeNode*> next_level;

        to_process.push(root);

        int current_level = 0;

        while (to_process.size() > 0) {
            vector<int> level;
            current_level++;

            while (to_process.size() > 0) {
                TreeNode* node = to_process.top();
                to_process.pop();

                // process
                level.push_back(node -> val);

                // make sure `next_level` is either staright or reverse
                // So, [4, 5, 6, 7] should remain that, or become [7, 6, 5, 4]
                // It shouldn't become something weird like [6, 7, 4, 5]
                if (current_level % 2 == 1) {
                    // If wer'e at an odd level, push left->right
                    // when the `next_level` stack is processed, the
                    // node will be reversed (so, in the next iteration,
                    // the level will be even, and nodes will be processed
                    // in right->left order)
                    if (node -> left != NULL) {
                        next_level.push(node -> left);
                    }

                    if (node -> right != NULL) {
                        next_level.push(node -> right);
                    }
                } else {
                    // If current_level is even, push right->left
                    // In the next iteration, these will be processed
                    // left->right because of stack
                    if (node -> right != NULL) {
                        next_level.push(node -> right);
                    }

                    if (node -> left != NULL) {
                        next_level.push(node -> left);
                    }
                }
            }

            // to_process is empty now, ans we want to process `next_level`
            // in the enxt iteration
            swap(to_process, next_level);

            ans.push_back(level);
        }

        return ans;
    }
};