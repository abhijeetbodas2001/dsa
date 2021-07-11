class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> dfs;
        vector<int> in_order;
        TreeNode* curr = root;
        while (dfs.size() > 0 || curr != NULL) {
            while (curr != NULL) {
                dfs.push(curr);
                curr = curr -> left;
            }

            curr = dfs.top();
            dfs.pop();
            // process curr
            in_order.push_back(curr -> val);
            curr = curr -> right;
        }
        
        return in_order;
    }
};
