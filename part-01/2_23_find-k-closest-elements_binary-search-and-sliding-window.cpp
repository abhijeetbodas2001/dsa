// Problem: https://leetcode.com/problems/find-k-closest-elements/

// O(k + log(n)) time, O(1) extra space.
// This is a kinda dubious method. The other one is better.

class Solution {
private:
	int isCloser(vector<int>& arr, int len, int i, int j, int x) {
		// Returns true if `i`th element is closer to `x` than the
		// `j`th element, as per the definition given in the problem.
		return (abs(arr[i] - x) < abs(arr[j] - x)) || ((abs(arr[i] - x) == abs(arr[j] - x)) && i < j);
	}

	int findClosestIndex(vector<int>& arr, int len, int x) {
		// Finds the array element which is **objectively** closest to `x`, and returns it's
		// index.
		// Vanilla binary search. `mid` will end up at the element closest to `x`
		
		// Note: Don't use `isCloser()` here! We want to find the closest element **only by value**,
		// and the position does not matter.
		int left = 0;
		int right = len - 1;
		int mid;
		
		while (left <= right) {
			mid = (left + right) / 2;
			if (arr[mid] == x) {
				return mid;
			} else if (arr[mid] > x) {
				right = mid - 1;
			} else if (arr[mid] < x) {
				left = mid + 1;
			}
		}


		// Note: In situations where the given number does not exist in the array, and there are
		// two values closest to given number, we want to deterministically return the lesser one
		// or the higher one. Here, we choose to return the lower one. (we have right < left right now)
		return right;

		// Example: arr = [1, 2, 2, 4, 4, 5] and x = 3, then this will return 2.
	}
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int len = arr.size();
		assert(k <= len);
		
		int closest = findClosestIndex(arr, len, x);

		// Take the two pointers to be consecutive, so that we start with zero output elements
		// and build the output array.
		// Because `findClosestElements` returned the lower number, take that and one higher than it
		// as pointers.
		int left = closest;
		int right = closest + 1;
		
		// This is the bottleneck for worst case complexity, because `k` could be
		// as high as `n`
		while (k > 0) {
			if (left == -1) {
				right++;
			} else if (right == len) {
				left--;
			} else {
				if (isCloser(arr, len, left, right, x)) {
					left--;
				} else {
					right++;
				}
			}
			
			k--;
		}
		
		vector<int> ans;
		// All elements between `start` and `end` should go in `ans` now.
		for (int i = left + 1; i <= right - 1; i++) {
			ans.push_back(arr[i]);
		}
		
		return ans;
    }
};