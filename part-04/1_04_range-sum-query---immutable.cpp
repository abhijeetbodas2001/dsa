// Problem: https://leetcode.com/problems/range-sum-query-immutable/

// Simple prefix sums

class NumArray {
private:
    vector<int> nums;
    vector<int> prefix_sum;
public:
    NumArray(vector<int>& nums) {
        nums = nums;
        prefix_sum.push_back(nums[0]);

        for (int i = 1; i < nums.size(); i++) {
            prefix_sum.push_back(prefix_sum[i - 1] + nums[i]);
        }
    }
    
    int sumRange(int left, int right) {
        if (left == 0) {
            return prefix_sum[right];
        }
        return prefix_sum[right] - prefix_sum[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */