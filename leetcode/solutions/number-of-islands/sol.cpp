// Problem: https://leetcode.com/problems/number-of-islands/

// Plain DFS
// O(m*n) time and space

class Solution {
private:
    bool isLand(int i, int j, vector<vector<char>>& grid) {
        if (
            0 <= i &&
            i < grid.size() &&
            0 <= j &&
            j < grid[0].size()
        ) {
            return grid[i][j] == '1';
        } else {
            return false;
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        bool visited[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                visited[i][j] = false;
            }
        }

        int num_islands = 0;

        // Direction vectors
        int x[4] = {1, 0, -1, 0};
        int y[4] = {0, 1, 0, -1};

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (!isLand(i, j, grid)) {
                    continue;
                }

                if (visited[i][j]) {
                    continue;
                }

                // Iterative dfs
                stack<vector<int>> dfs;
                vector<int> root{i, j};
                dfs.push(root);
                while (dfs.size() > 0) {
                    vector<int> node = dfs.top();
                    dfs.pop();

                    if (visited[node[0]][node[1]]) {
                        continue;
                    }

                    visited[node[0]][node[1]] = true;
                    for (int k = 0; k < 4; k++) {
                        if (!isLand(node[0] + x[k], node[1] + y[k], grid)) {
                            continue;
                        }

                        vector<int> nbr{node[0] + x[k], node[1] + y[k]};
                        dfs.push(nbr);
                    }
                }

                // The dfs just processed an island
                num_islands++;
            }
        }

        return num_islands;
    }
};