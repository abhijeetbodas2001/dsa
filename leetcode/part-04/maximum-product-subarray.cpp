// Problem: https://leetcode.com/problems/maximum-product-subarray/

// O(N) time, O(1) space
// See https://leetcode.com/problems/maximum-product-subarray/discuss/48230/Possibly-simplest-solution-with-O(n)-time-complexity
// and https://leetcode.com/problems/maximum-product-subarray/discuss/48230/Possibly-simplest-solution-with-O(n)-time-complexity/48320

/*
Copied from comment:
This is very similar to the " max cumulative sum subarray" problem. Here you keep 2 values: the max cumulative
product UP TO current element starting from SOMEWHERE in the past, and the minimum cumuliative product UP TO current element.
It would be easier to see the DP structure if we store these 2 values for each index, like maxProduct[i],minProduct[i].

At each new element, you could either add the new element to the existing product, or start fresh the product from current
index (wipe out previous results), hence the 2 Math.max() lines.

If we see a negative number, the "candidate" for max should instead become the previous **min** product, because a bigger number
multiplied by negative becomes smaller, hence the swap()
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();

        // store the result that is the max we have found so far
        int ans = nums[0];

        // imax/imin stores the max/min product of
        // subarray that ends with the current number A[i]
        int imin = ans;
        int imax = ans;

        for (int i = 1; i < len; i++) {
            // multiplied by a negative makes big number smaller, small number bigger
            // so we redefine the extremums by swapping them
            if (nums[i] < 0)
                swap(imax, imin);

            // max/min product for the current number is either the current number itself
            // or the max/min by the previous number times the current one
            imax = max(nums[i], imax * nums[i]);
            imin = min(nums[i], imin * nums[i]);

            // the newly computed max value is a candidate for our global result
            ans = max(ans, imax);
        }
        return ans;       

    }
};