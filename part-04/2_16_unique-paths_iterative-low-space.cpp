// Problem: https://leetcode.com/problems/unique-paths/

// O(m*n) time, O(n) space solution

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) {
            // base cases
            return 1;
        }

        // stores answers for the previous row
        vector<int> prev_row(n, 1);

        // store the answer for the cell to the left of current cell
        int left;

        // answer for the current row
        int current;

        for (int i = 1; i < m; i++) {
            left = 1;
            vector<int> current_row;
            current_row.push_back(1);
            for (int j = 1; j < n; j++) {
                // calculate answer for current cell
                current = left + prev_row[j];

                // book-keeping
                left = current;
                current_row.push_back(current);
            }
            prev_row = current_row;
        }

        return current;
    }
};