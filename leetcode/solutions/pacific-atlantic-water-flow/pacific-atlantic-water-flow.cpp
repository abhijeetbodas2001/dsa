// Problem: https://leetcode.com/problems/pacific-atlantic-water-flow/

// SOLUTION IS INCOMPLETE

class Solution {
private:
    int rows;
    int cols;

    // Direction vectors
    int x[4] = {0, 1, 0, -1};
    int y[4] = {1, 0, -1, 0};

    bool onLand(int i, int j) {
        // Returns whether a point lies within the island
        return (
            0 <= i &&
            i < rows &&
            0 <= j &&
            j < cols
        );
    }

    void initialize2DVector(vector<vector<bool>> v) {
        for (int i = 0; i < rows; i++) {
            int 
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                v[i][j] = false;
            }
        }
    }

    void buildReach(
        int i,
        int j,
        vector<vector<int>>& heights,
        unordered_set<pair<int, int>>& reachable_points,
        unordered_set<pair<int, int>>& visited
    ) {
        if (!onLand(i, j)) {
            return;
        }

        if (visited.find({i, j}) != visited.end()) {
            return;
        }
        visited.insert({i, j});

        bool reachable = reachable_points.find({i, j}) != reachable_points.end();
        for (int v = 0; v < 4; v++) {
            int i_nbr = i + x[v];
            int j_nbr = j + y[v];

            if (reachable && heights[i_nbr][j_nbr] >= heights[i][j]) {
                reachable_points.insert({i_nbr, j_nbr});
            }

            buildReach(i_nbr, j_nbr, heights, reachable_points, visited);
        }
    }

    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size();
        cols = heights[0].size();

        // Stores the points from which water can flow to the pacific
        bool pacific_reach[rows][cols];
        initialize2DArray(pacific_reach);

        // Stores the points from which water can flow to the altantic
        bool atlantic_reach[rows][cols];
        initialize2DArray(atlantic_reach);


        for (int j = 0; j < cols; j++) {
            pacific_reach.insert({0, j});
            // IMPORTANT TO CREATE NEW
            bool visited[i][j];
            initialize2DArray(visited);
            buildReach(0, j, heights, pacific_reach, visited);
        }
        for (int i = 0; i < rows; i++) {
            pacific_reach.insert({i, 0});
            visited.clear();
            buildReach(i, 0, heights, pacific_reach, visited);
        }

        // Stores the points from which water can flow to the altantic
        unordered_set<pair<int, int>> atlantic_reach;
        for (int j = 0; j < cols; j++) {
            atlantic_reach.insert({rows - 1, j});
            visited.clear();
            buildReach(rows - 1, j, heights, atlantic_reach, visited);
        }
        for (int i = 0; i < rows; i++) {
            atlantic_reach.insert({i, cols - 1});
            visited.clear();
            buildReach(i, cols - 1, heights, atlantic_reach, visited);
        }

        vector<vector<int>> ans;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (
                    pacific_reach.find({i, j}) != pacific_reach.end() &&
                    atlantic_reach.find({i, j}) != atlantic_reach.end()
                ) {
                    vector<int> v;
                    v.push_back(i);
                    v.push_back(j);
                    ans.push_back(v);
                }
            }
        }

        return ans;
    }
};