// Problem: https://leetcode.com/problems/set-matrix-zeroes/

// O(m*n) time, O(1) space.
// Logic is same as the o(m+n) space solution, but instead of using
// extra vectors to store bools for if row/column has a zero, store that
// information in the matrix itself, by setting the first element of
// that row/column to zero.
// Take special care for the first row and first column.

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();	// "m"
		int columns = matrix[0].size(); 	// "n"
		
		bool row0_has_0 = false;
		for (int j = 0; j < columns; j++) {
			if (matrix[0][j] == 0) {
				row0_has_0 = true;
			}
		}
		
		bool column0_has_0 = false;
		for (int i = 0; i < rows; i++) {
			if (matrix[i][0] == 0) {
				column0_has_0 = true;
			}
		}
		
		
		for (int i = 1; i < rows; i++) {
			for (int j = 1; j < columns; j++) {				
				if (matrix[i][j] == 0) {
					matrix[i][0] = 0;
					matrix[0][j] = 0;
				}
			}
		}
		
		// Set all elements of required rows (except the first row) to zero.
		for (int i = 1; i < rows; i++) {
			if (matrix[i][0] == 0) {
				for (int j = 1; j < columns; j++) {
					matrix[i][j] = 0;
				}
			}
		}
		
		// Set all elements of required columns (except the first column) to zero.
		for (int j = 1; j < columns; j++) {
			if (matrix[0][j] == 0) {
				for (int i = 1; i < rows; i++) {
					matrix[i][j] = 0;
				}
			}
		}
		
		// Handle first row.
		if (row0_has_0) {
			for (int j = 0; j < columns; j++) {
				matrix[0][j] = 0;
			}
		}
		
		// Handle first column.
		if (column0_has_0) {
			for (int i = 0; i < rows; i++) {
				matrix[i][0] = 0;
			}
		}
    }
};