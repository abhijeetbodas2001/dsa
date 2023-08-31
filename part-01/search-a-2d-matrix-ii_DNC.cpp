// Problem: https://leetcode.com/problems/search-a-2d-matrix-ii/

// Recursive binary (3/4 -ary?) search
// Be super-careful with boundaries!

class Solution {
private:
	bool searchInSubmatrix(vector<vector<int>>& matrix, int top, int right, int bottom, int left, int target) {
		// Searches for target in submatrix between top&bottom rows and left&right columns (both included)
		if (top > bottom || left > right) {
			return false;
		}
		
		if (top == bottom && right == left) {
			return matrix[top][right] == target;
		}
		
		int rows = matrix.size();
		int columns = matrix[0].size();
		int mid_row = (top + bottom) / 2;
		int mid_column = (right + left) / 2;
		int mid_elem = matrix[mid_row][mid_column];
		
		if (mid_elem == target) {
			return true;
		} else if (mid_elem > target) {
			return (
				searchInSubmatrix(matrix, top, mid_column - 1, mid_row - 1, left, target) ||	// top-left part
				searchInSubmatrix(matrix, top, right, mid_row - 1, mid_column, target) ||	// top right part
				searchInSubmatrix(matrix, mid_row, mid_column - 1, bottom, left, target)	// bottom left part
			);
		} else {
			assert(mid_elem < target);
			return (
				searchInSubmatrix(matrix, mid_row + 1, right, bottom, mid_column + 1, target) ||	// bottom right part
				searchInSubmatrix(matrix, top, right, mid_row, mid_column + 1, target) ||	// top right part
				searchInSubmatrix(matrix, mid_row + 1, mid_column, bottom, left, target)	// bottom left part
			);
		}
	}
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int rows = matrix.size();
		int columns = matrix[0].size();
        return searchInSubmatrix(matrix, 0, columns - 1, rows - 1, 0, target);
    }
};