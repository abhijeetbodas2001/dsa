// Problem: https://leetcode.com/problems/container-with-most-water/

// O(n) time, O(1) extra space
// Greedy, two pointers

class Solution {
private:
    int getArea(int i, int j, vector<int>& height) {
        assert(j >= i);
        assert(0 <= i && i <= height.size());
        assert(0 <= j && j <= height.size());

        return (j - i) * min(height[i], height[j]);
    }
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int left = 0;
        int right = len - 1;
        int ans = 0;

        while (left <= right) {
            ans = max(ans, getArea(left, right, height));

            if (height[left] < height[right]) {
                // If `height[left] < height[right]`, we know that none of [left, i] for
                // `i < right` can be miximal solution, since they definitely have a lesser area.
                // So move `left` ahead.
                left++;
            } else if (height[left] > height[right]) {
                // If `height[left] > height[right]`, we know that none of [i, right] for
                // `i > left` can be miximal solution, since they definitely have a lesser area.
                // So move `right` behind.
                right--;
            } else if (height[left] == height[right]) {
                // In this case, it doesn't really matter what we move.
                left++;
            }
        }

        return ans;
    }
};