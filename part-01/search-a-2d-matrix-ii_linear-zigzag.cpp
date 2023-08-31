// Problem: https://leetcode.com/problems/search-a-2d-matrix-ii/submissions/

// O(m+n) time!

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
		int columns = matrix[0].size();
		
		// One could also start at the bottom left corner.		
		int row = 0;
		int column = columns - 1;
		
		while (row <= rows - 1 && column >= 0) {
			if (matrix[row][column] == target) {
				return true;
			} else if (matrix[row][column] > target) {
				// If we want something smaller than current element, the current column
				// is useless.
				column--;
			} else if (matrix[row][column] < target) {
				// If we want something smaller than current element, the row column
				// is useless.
				row++;
			}
		}
		
		return false;
    }
};