// Problem: https://leetcode.com/problems/minimum-height-trees/

/*
COPIED FROM DISCUSS

It is easy to see that the root of an MHT has to be the middle point (or two middle points) of
the longest path of the tree.
Though multiple longest paths can appear in an unrooted tree, they must share the same middle point(s).

Computing the longest path of a unrooted tree can be done, in O(n) time, by tree dp, or simply 2 tree
traversals (dfs or bfs). The following is some thought of the latter.

Randomly select a node x as the root, do a dfs/bfs to find the node y that has the longest distance from x.
Then y must be one of the endpoints on some longest path.
Let y the new root, and do another dfs/bfs. Find the node z that has the longest distance from y.

Now, the path from y to z is the longest one, and thus its middle point(s) is the answer. Java Solution
*/

class Solution {
private:
    vector<int> depths;
    vector<vector<int>> nbrs;
    vector<bool> visited;
    vector<int> ans;
    vector<int> parent;

    void saveDepths(int root, int curr_depth) {
        visited[root] = true;
        depths[root] = curr_depth;

        for (int i = 0; i < nbrs[root].size(); i++) {
            int child = nbrs[root][i];

            if (!visited[child]) {
                // Save the parent of each node, to backtrack later on
                parent[child] = root;
                saveDepths(child, curr_depth + 1);
            }
        }
    }

    int getMaxDepNode() { 
        int node = 0;
        int max_dep = depths[0];

        for (int i = 0; i < depths.size(); i++) {
            if (depths[i] > max_dep) {
                node = i;
                max_dep = depths[i];
            }
        }

        return node;
    }

    void resetState() {
        for (int i = 0; i < visited.size(); i++) {
            parent[i] = -1;
            visited[i] = false;
            depths[i] = -1;
        }
    }
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            // edge case
            vector<int> v{0};
            return v;
        }

        nbrs.resize(n);
        depths.resize(n);
        visited.resize(n);
        parent.resize(n);

        for (int i = 0; i < edges.size(); i++) {
            vector<int> edge = edges[i];
            nbrs[edge[0]].push_back(edge[1]);
            nbrs[edge[1]].push_back(edge[0]);
        }

        // find one end of the longest path
        resetState();
        saveDepths(0, 0);
        int start = getMaxDepNode();

        // find the other end of the longest path
        resetState();
        saveDepths(start, 0);
        int end = getMaxDepNode();

        // `start` was the root for the dfs done just now, so it shouldn't
        // have a parent
        assert(parent[start] == -1);

        // generate the path, using the parent data saved in `saveDepths`
        vector<int> path;
        while (end != -1) {
            // if `end` reaches -1, we have compeleted tracing the longest path
            path.push_back(end);
            end = parent[end];
        }

        // return the middle nodes
        int len = path.size();
        if (len % 2 == 1) {
            vector<int> v{path[len / 2]};
            return v;
        } else {
            vector<int> v{path[len / 2], path[len / 2 - 1]};
            return v;
        }
    }
};