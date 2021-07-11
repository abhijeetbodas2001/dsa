// Problem: https://leetcode.com/problems/course-schedule/

// DFS with keeping track of the path
// Don't do iterative!
// It is difficult to remember the path in iterative solutions

// A simple version would be to create a `bool is_in_path` array to store if the
// node is in path, than making a set. That wouldn't worsen the space complexity
// because the `visisted` array is O(N) space anyways

class Solution {
private:
    vector<bool> visited;
    bool isCyclic (int root, vector<vector<int>>& children, unordered_set<int>& nodes_in_path) {
        if (visited[root]) {
            if (nodes_in_path.find(root) != nodes_in_path.end()) {
                return true;
            } else {
                return false;
            }
        }

        visited[root] = true;
        nodes_in_path.insert(root);

        for (int i = 0; i < children[root].size(); i++) {
            int child = children[root][i];
            if (isCyclic(child, children, nodes_in_path)) {
                return true;
            }
        }

        nodes_in_path.erase(root);
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> children;
        for (int i = 0; i < numCourses; i++) {
            // Initialize children to empty arrays
            vector<int> v;
            children.push_back(v);
        }

        for (int i = 0; i < prerequisites.size(); i++) {
            // Setup children
            int child = prerequisites[i][0];
            int parent = prerequisites[i][1];
            children[parent].push_back(child);
        }

        visited.resize(numCourses, false);

        for (int i = 0; i < numCourses; i++) {
            if (visited[i]) {
                continue;
            }

            unordered_set<int> nodes_in_path;
            if (isCyclic(i, children, nodes_in_path)) {
                return false;
            }
        }

        // No cycles were detected
        return true;
    }
};