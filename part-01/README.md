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
|01|Easy|[Contains Duplicate](https://leetcode.com/problems/contains-duplicate/)|[Solution](/part-01/1_01_contains-duplicate.cpp)|
|02|Easy|[Missing Number](https://leetcode.com/problems/missing-number/)|[Solution (bit manipulation)](/part-01/1_02_missing-number_bit.cpp), [Solution (number sums)](/part-01/1_02_missing-number_sum.cpp)|
|03|Easy|[Find All Numbers Disappeared in an Array](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/)|[Solution](/part-01/1_03_find-all-numbers-disappeared-in-an-array.cpp)|
|04|Easy|[Single Number](https://leetcode.com/problems/single-number/)|[Solution](/part-01/1_04_single-number.cpp)|
|05|Easy|[Counting Bits](https://leetcode.com/problems/counting-bits/)|[Solution](/part-01/1_05_counting-bits.cpp)|
|06|Easy|[Binary Search](https://leetcode.com/problems/binary-search/)|[Solution](/part-01/1_06_binary-search.cpp)|
|07|Easy|[Find Smallest Letter Greater Than Target](https://leetcode.com/problems/find-smallest-letter-greater-than-target/)|[Solution](/part-01/1_07_find-smallest-letter-greater-than-target.cpp)|
|08|Easy|[Peak Index in a Mountain Array](https://leetcode.com/problems/peak-index-in-a-mountain-array/)|[Solution](/part-01/1_08_peak-index-in-a-mountain-array.cpp)|
|09|Easy|[Majority Element](https://leetcode.com/problems/majority-element/)|[Solution (Boyer Moore algorithm)](/part-01/1_09_majority-element_boyer-moore.cpp), [Solution (sorting)](/part-01/1_09_majority-element_sorting.cpp)|
|10|Medium|[Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/)|[Solution (extra space)](/part-01/2_10_product-of-array-except-self_extra-space.cpp), [Solution (no extra space)](/part-01/2_10_product-of-array-except-self_no-extra-space.cpp)|
|11|Medium|[Find the Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number/)|[Solution (TODO)](/part-01/2_11_find-the-duplicate-number.cpp)|
|12|Medium|[Find All Duplicates in an Array](https://leetcode.com/problems/find-all-duplicates-in-an-array/)|[Solution](/part-01/2_12_find-all-duplicates-in-an-array.cpp)|
|13|Medium|[Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes/)|[Solution (`O(1) space`)](/part-01/2_13_set-matrix-zeroes_o1-space.cpp), [Solution (`O(m+n)` space)](/part-01/2_13_set-matrix-zeroes_Om+n-space.cpp)|
|14|Medium|[Spiral Matrix](https://leetcode.com/problems/spiral-matrix/)|[Solution](/part-01/2_14_spiral-matrix.cpp)|
|15|Medium|[Rotate Image](https://leetcode.com/problems/rotate-image/)|[Solution](/part-01/2_15_rotate-image.cpp)|
|16|Medium|[Kth Smallest Element in a Sorted Matrix](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/)|[Solution (TODO)](/part-01/2_16_kth-smallest-element-in-a-sorted-matrix.cpp)|
|17|Medium|[Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/)|[Solution](/part-01/2_17_find-minimum-in-rotated-sorted-array.cpp)|
|18|Medium|[Find Peak Element](https://leetcode.com/problems/find-peak-element/)|[Solution](/part-01/2_18_find-peak-element.cpp)|
|19|Medium|[Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/)|[Solution](/part-01/2_19_search-in-rotated-sorted-array.cpp)|
|20|Medium|[Search in Rotated Sorted Array II](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/)|[Solution](/part-01/2_20_search-in-rotated-sorted-array-ii.cpp)|
|21|Medium|[Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/)|[Solution](/part-01/2_21_search-a-2d-matrix.cpp)|
|22|Medium|[Search a 2D Matrix II](https://leetcode.com/problems/search-a-2d-matrix-ii/)|[Solution (DNC)](/part-01/2_22_search-a-2d-matrix-ii_DNC.cpp), [Solution (linear, zigzag)](/part-01/2_22_search-a-2d-matrix-ii_linear-zigzag.cpp)|
|23|Medium|[Find K Closest Elements](https://leetcode.com/problems/find-k-closest-elements/)|(**Try this again**) [Solution (binary search with sliding window)](/part-01/2_23_find-k-closest-elements_binary-search-and-sliding-window.cpp), [Solution (Binary search to find left bound)](/part-01/2_23_find-k-closest-elements_binary-search-left-bound.cpp)|
|24|Hard|[First Missing Positive](https://leetcode.com/problems/first-missing-positive/)|[Solution (TODO)](/part-01/3_24_first-missing-positive.cpp)|
|25|Hard|[Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/)|[Solution (TODO)](/part-01/3_25_longest-consecutive-sequence.cpp)|
|26|Hard|[Count of Range Sum](https://leetcode.com/problems/count-of-range-sum/)|[Solution (TODO)](/part-01/3_26_count-of-range-sum.cpp)|
|27|Hard|[Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/)|[Solution (TODO)](/part-01/3_27_median-of-two-sorted-arrays.cpp)|


