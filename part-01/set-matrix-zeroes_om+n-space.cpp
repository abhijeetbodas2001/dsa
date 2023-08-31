// Problem: https://leetcode.com/problems/set-matrix-zeroes/

// O(m*n) time, O(m + n) space.

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();	// "m"
		int columns = matrix[0].size(); 	// "n"
		
		vector<bool> is_row_zero(rows, false);
		vector<bool> is_column_zero(columns, false);
		
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				if (matrix[i][j] == 0) {
					is_row_zero[i] = true;
					is_column_zero[j] = true;
				}
			}
		}
		
		
		// Set all elements of required rows to zero
		for (int i = 0; i < rows; i++) {
			if (is_row_zero[i]) {
				for (int j = 0; j < columns; j++) {
					matrix[i][j] = 0;
				}
			}
		}
		
		// Set all elements of required columns to zero
		for (int j = 0; j < columns; j++) {
			if (is_column_zero[j]) {
				for (int i = 0; i < rows; i++) {
					matrix[i][j] = 0;
				}
			}
		}
    }
};