// Problem: https://leetcode.com/problems/search-a-2d-matrix/

// Two time binary search. Once for height, once for width.
// O(log(m) + log(n)) time, no extra space.

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
		int columns = matrix[0].size();
		int top = 0;
		int bottom = rows - 1;
		int mid_row;
		
		while (true) {
			if (top > bottom) {
				return false;
			}
			mid_row = (top + bottom) / 2;
			
			if (matrix[mid_row][0] <= target && target <= matrix[mid_row][columns - 1]) {
				break;
			} else if (matrix[mid_row][0] > target) {
				bottom = mid_row - 1;
			} else if (matrix[mid_row][columns - 1] < target) {
				top = mid_row + 1;
			}
		}
		
		assert(matrix[mid_row][0] <= target && target <= matrix[mid_row][columns - 1]);
		
		int left = 0;
		int right = columns - 1;
		int mid_column = 0;
		
		while (left <= right) {
			mid_column = (left + right) / 2;
			if (matrix[mid_row][mid_column] == target) {
				return true;
			} else if (matrix[mid_row][mid_column] > target) {
				right = mid_column - 1;
			} else if (matrix[mid_row][mid_column] < target) {
				left = mid_column + 1;
			}
		}
		
		return false;
    }
};