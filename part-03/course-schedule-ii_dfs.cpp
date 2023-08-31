// Problem: https://leetcode.com/problems/course-schedule-ii/

// Cycle detection/topological sorting using DFS
// O(V + E) time (we visite all nodes and process all edges)
// O(V + E) total space
//      O(E) for storing the `neighbors` structure
//      O(V) for the recursion stack

class Solution {
private:
    vector<bool> visited;
    vector<bool> in_path;
    vector<int> topo;

    bool dfs(int root, vector<vector<int>>& neighbors) {
        // Returns true if graph is cyclic
        if (visited[root]) {
            if (in_path[root]) {
                // root has been visited earlier and is also in the current recursion
                // stack, so a cycle must exist
                return true;
            } else {
                return false;
            }
        }

        visited[root] = true;
        in_path[root] = true;

        for (int i = 0; i < neighbors[root].size(); i++) {
            int child = neighbors[root][i];
            if (dfs(child, neighbors)) {
                return true;
            }
        }

        in_path[root] = false;

        // NOTE: root is pushed into `topo` AFTER all it's children
        // this means the ordering of `topo` is actually the reverse of
        // the actual topological ordering
        topo.push_back(root);
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> neighbors(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            int child = prerequisites[i][0];
            int parent = prerequisites[i][1];
            neighbors[parent].push_back(child);
        }

        visited.resize(numCourses, false);
        in_path.resize(numCourses, false);

        for (int i = 0; i < numCourses; i++) {
            if (visited[i]) {
                continue;
            }

            int root = i;
            if (dfs(root, neighbors)) {
                vector<int> empty_vector;
                return empty_vector;
            }
        }

        // The `dfs` pushed the nodes in the reverse order, i.e, the children first,
        // and then the parent. So, reverse it to get the correct order.
        // We could have instead pushed it in the correct order in `dfs` itself,
        // but that would have involved keeping track of indices etc.
        reverse(topo.begin(), topo.end());
        return topo;
    }
};