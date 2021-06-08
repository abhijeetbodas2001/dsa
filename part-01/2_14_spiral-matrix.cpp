// Problem: https://leetcode.com/problems/spiral-matrix/

// O(m*n) time, O(1) space
// Simulation.

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int first_row = 0;
		int last_row = matrix.size() - 1;
		int first_column = 0;
		int last_column = matrix[0].size() - 1;
		
		vector<int> ans;
		
		while(true) {
			if (first_column > last_column) {
				break;
			}
			
			// Traverse `first_row` (left to right)
			for (int j = first_column; j <= last_column; j++) {
				ans.push_back(matrix[first_row][j]);
			}
			first_row++;
			
			if (first_row > last_row) {
				break;
			}
			
			// Traverse `last_column` (up to down)
			for (int i = first_row; i <= last_row; i++) {
				ans.push_back(matrix[i][last_column]);
			}
			last_column--;
			
			if (first_column > last_column) {
				break;
			}
			
			// Traverse `last_row` (right to left)
			for (int j = last_column; j >= first_column; j--) {
				ans.push_back(matrix[last_row][j]);
			}
			last_row--;
			
			if (first_row > last_row) {
				break;
			}
			
			// Traverse `first_column` (down to up)
			for (int i = last_row; i >= first_row; i--) {
				ans.push_back(matrix[i][first_column]);
			}
			first_column++;
		}
		
		return ans;
    }
};