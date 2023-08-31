## Contents

This part contains problems on these topics:
- Arrays
- Binary search
- Sorting
- Bit manipulation


## Notes

- Check carefully if the questions asks for the "index" or the "number"/"element"

- Binary search
	- Whether the number given is present in the array or not, in a vanilla B.S, the `mid`
will always end up in the element in the array which is closest to the given number.
	- Write vanilla B.S first. Look at what are the constraints on `mid`, and then handle
them inside/outside the loop. Use `while (true)` when the answer is definitely present
or is  guaranteed by the problem.

- To check if a number is power of 2 quickly:
	```
	bool ispowerof2(int n){
		return (n & (n-1)) == 0;
	}
	```

## Problems

|Serial number|Difficulty|Problem|Solution(s)|
|-|-|-|-|
|01|Easy|[Contains Duplicate](https://leetcode.com/problems/contains-duplicate)|
|02|Easy|[Missing Number](https://leetcode.com/problems/missing-number)|
|03|Easy|[Find All Numbers Disappeared in an Array](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array)|
|04|Easy|[Single Number](https://leetcode.com/problems/single-number)|
|05|Easy|[Counting Bits](https://leetcode.com/problems/counting-bits)|
|06|Easy|[Binary Search](https://leetcode.com/problems/binary-search)|
|07|Easy|[Find Smallest Letter Greater Than Target](https://leetcode.com/problems/find-smallest-letter-greater-than-target)|
|08|Easy|[Majority Element](https://leetcode.com/problems/majority-element)|
|09|Easy|[Convert 1D Array Into 2D Array](https://leetcode.com/problems/convert-1d-array-into-2d-array)|
|10|Easy|[Move Zeroes](https://leetcode.com/problems/move-zeroes)|
|11|Medium|[Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self)|
|12|Medium|[Find the Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number)|
|13|Medium|[Find All Duplicates in an Array](https://leetcode.com/problems/find-all-duplicates-in-an-array)|
|14|Medium|[Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes)|
|15|Medium|[Spiral Matrix](https://leetcode.com/problems/spiral-matrix)|
|16|Medium|[Rotate Image](https://leetcode.com/problems/rotate-image)|
|17|Medium|[Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence)|
|18|Medium|[Kth Smallest Element in a Sorted Matrix](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix)|
|19|Medium|[Peak Index in a Mountain Array](https://leetcode.com/problems/peak-index-in-a-mountain-array)|
|20|Medium|[Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array)|
|21|Medium|[Find Peak Element](https://leetcode.com/problems/find-peak-element)|
|22|Medium|[Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array)|
|23|Medium|[Search in Rotated Sorted Array II](https://leetcode.com/problems/search-in-rotated-sorted-array-ii)|
|24|Medium|[Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix)|
|25|Medium|[Search a 2D Matrix II](https://leetcode.com/problems/search-a-2d-matrix-ii)|
|26|Medium|[Find K Closest Elements](https://leetcode.com/problems/find-k-closest-elements)|
|27|Medium|[Factor Combinations](https://leetcode.com/problems/factor-combinations)|
|28|Hard|[First Missing Positive](https://leetcode.com/problems/first-missing-positive)|
|29|Hard|[Count of Range Sum](https://leetcode.com/problems/count-of-range-sum)|
|30|Hard|[Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays)|
