// Problem: https://leetcode.com/problems/path-sum/

// DFS, recursive
// O(n) time
// O(log(n)) to O(n) stack space

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
    bool isLeaf(TreeNode* node) {
        assert(node != NULL);
        return node -> left == NULL && node -> right == NULL;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL) {
            return false;
        }

        // We store two things -- the node, and the value of the sum till that
        // node (not including the node).
        stack<pair<TreeNode*, int>> dfs;
        dfs.push(make_pair(root, 0));
        while (dfs.size() > 0) {
            pair<TreeNode*, int> elem = dfs.top();
            dfs.pop();
            TreeNode* node = elem.first;
            int sum_above = elem.second;

            assert(node != NULL);
            int current_sum = sum_above + node -> val;
            if (isLeaf(node)) {
                if (current_sum == target) {
                    return true;
                } else {
                    continue;
                }
            }

            if (node -> left != NULL) {
                dfs.push(make_pair(node -> left, current_sum));
            }

            if (node -> right != NULL) {
                dfs.push(make_pair(node -> right, current_sum));
            }
        }

        return false;
    }
};
