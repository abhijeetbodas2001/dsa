// Problem: https://leetcode.com/problems/rotate-image/

class Solution {
private:
	void swapClockWise (int *a, int *b, int *c, int *d) {
		int temp;
		temp = *d;
		*d = *c;
		*c = *b;
		*b = *a;
		*a = temp;
	}
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
		int nby2_ceil = (n % 2 == 0 ? n / 2 : n / 2 + 1);
		
		// Note the bounds. `i` should not handle the middle row for odd-n matrices -- `j` will do that.
		for (int i = 0; i < n/2; i++) {
			for (int j = 0; j < nby2_ceil; j++) {
				swapClockWise(&matrix[i][j], &matrix[j][n - 1 - i], &matrix[n - 1 - i][n - 1 - j], &matrix[n - 1 - j][i]);
			}
		}
    }
};