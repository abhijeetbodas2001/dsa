// Problem: https://leetcode.com/problems/course-schedule-ii/

// in-degree method
// See official solution for explaination and complexity analysis

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);

        vector<vector<int>> neighbors(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            int child = prerequisites[i][0];
            int parent = prerequisites[i][1];
            neighbors[parent].push_back(child);

            indegree[child] = indegree[child] + 1;
        }

        vector<int> topo(numCourses, 0);
        int index_to_set = 0;

        vector<int> empty_vector;

        queue<int> zero_indegree_nodes;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                zero_indegree_nodes.push(i);
            }
        }

        while (zero_indegree_nodes.size() > 0) {
            int node = zero_indegree_nodes.front();
            zero_indegree_nodes.pop();

            topo[index_to_set] = node;
            index_to_set = index_to_set + 1;

            for (int i = 0; i < neighbors[node].size(); i++) {
                int child = neighbors[node][i];
                indegree[child] = indegree[child] - 1;

                if (indegree[child] == 0) {
                    zero_indegree_nodes.push(child);
                }
            }
        }

        if (index_to_set < numCourses) {
            // the topo did not get completed
            // this means there is at least one cycle in the graph
            // Reasoning: If there is a cycle, some nodes will never reach indegree = 0
            //
            //  Consider:       A ➡ B ➡ C
            //                       ⬆    ⬇
            //                       E ⬅ D
            // Now, A will be processed first, but after it gets processed, none of the
            // other nodes (critically, B) reaches indegree zero, so the queue is empty
            // and loop will end without filling up `topo` completely.
            // This also means `index_to_set` never goes out of bounds (becomes >= numCourses)
            return empty_vector;
        }

        return topo;
    }
};