// Problem: https://leetcode.com/problems/minimum-height-trees/

// See https://leetcode.com/problems/minimum-height-trees/discuss/76055/Share-some-thoughts

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n <= 2) {
            // base cases
            vector<int> v;
            for (int i = 0; i < n; i++) {
                v.push_back(i);
            }
            return v;
        }

        vector<unordered_set<int>> nbrs(n);

        for (int i = 0; i < edges.size(); i++) {
            nbrs[edges[i][0]].insert(edges[i][1]);
            nbrs[edges[i][1]].insert(edges[i][0]);
        }

        int remaining_nodes = n;

        unordered_set<int> leaf_nodes;
        for (int i = 0; i < n; i++) {
            if (nbrs[i].size() == 1) {
                leaf_nodes.insert(i);
            }
        }

        // there can be at max two centroids
        while (remaining_nodes > 2) {
            // layer-by-layer prune the leaf nodes

            remaining_nodes = remaining_nodes - leaf_nodes.size();

            unordered_set<int> new_leaf_nodes;
            for (int node: leaf_nodes) {
                int parent = *nbrs[node].begin();
                nbrs[parent].erase(node);

                if (nbrs[parent].size() == 1) {
                    new_leaf_nodes.insert(parent);
                }
            }

            leaf_nodes = new_leaf_nodes;
        }

        // what remains are the centroids
        vector<int> ans;
        for (int node: leaf_nodes) {
            ans.push_back(node);
        }
        return ans;
    }
};