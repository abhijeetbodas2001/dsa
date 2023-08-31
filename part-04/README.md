## Contents

This part contains problems on these topics:
- Greedy
- Heap
- Dynamic Programming


## Notes

### When to use DP?

1. When asked to count something, like the number of ways in which something can be done
1. Minimize or maximize a certain value
1. YES/NO questions: is it possible to ... ?

For `2.` and `3.`, it is often possible that the problem can be solved using a simpler **greedy** algorithm.

### Implementing DP

DP algorithms can be implemented both iteratively and recursively.
The iterative solution is generally more concise and faster (because of lesser overhead),
but the recursive solution is easier to implement/understand. Iterative solutions are also
easier to modify/improve, so prefer the **iterative method**.

But before implementing anything at all, one must come up with a recurrence relation, and to
do that one must define the state / what exactly store.  
It is important to ask, at each `state`, the question:
```
When at a certain position / after some number of steps, what is important so far?
```

When the `state` is decided / defined, then think about how the state relates to
a smaller state, and try to write it as a combination of smaller states.
IOW, think about the question "how could I have gotten to this state?"
Often, drawing arrow diagrams helps in thinking about this.


### Complexity

When analysing the time complexity of the implementation, it is helpful to draw a tree
of the function calls for a recursive implementation.

## Problems

|Serial number|Difficulty|Problem|Solution(s)|
|-|-|-|-|
|01|Easy|[Climbing Stairs](https://leetcode.com/problems/climbing-stairs)|
|02|Easy|[Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock)|
|03|Easy|[Range Sum Query - Immutable](https://leetcode.com/problems/range-sum-query-immutable)|
|04|Easy|[Counting Bits](https://leetcode.com/problems/counting-bits)|
|05|Medium|[Target Sum](https://leetcode.com/problems/target-sum)|
|06|Medium|[House Robber](https://leetcode.com/problems/house-robber)|
|07|Medium|[Maximum Subarray](https://leetcode.com/problems/maximum-subarray)|
|08|Medium|[House Robber II](https://leetcode.com/problems/house-robber-ii)|
|09|Medium|[Coin Change](https://leetcode.com/problems/coin-change)|
|10|Medium|[Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray)|
|11|Medium|[Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence)|
|12|Medium|[Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring)|
|13|Medium|[Word Break](https://leetcode.com/problems/word-break)|
|14|Medium|[Combination Sum IV](https://leetcode.com/problems/combination-sum-iv)|
|15|Medium|[Decode Ways](https://leetcode.com/problems/decode-ways)|
|16|Medium|[Unique Paths](https://leetcode.com/problems/unique-paths)|
|17|Medium|[Jump Game](https://leetcode.com/problems/jump-game)|
|18|Medium|[Palindromic Substrings](https://leetcode.com/problems/palindromic-substrings)|
|19|Medium|[Number of Longest Increasing Subsequence](https://leetcode.com/problems/number-of-longest-increasing-subsequence)|
|20|Medium|[Partition Equal Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum)|
|21|Medium|[Partition to K Equal Sum Subsets](https://leetcode.com/problems/partition-to-k-equal-sum-subsets)|
|22|Medium|[Best Time to Buy and Sell Stock with Cooldown](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown)|
|23|Medium|[Kth Smallest Element in a Sorted Matrix](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix)|
|24|Medium|[Find K Pairs with Smallest Sums](https://leetcode.com/problems/find-k-pairs-with-smallest-sums)|
|25|Medium|[Meeting Rooms II](https://leetcode.com/problems/meeting-rooms-ii)|
|26|Medium|[Task Scheduler](https://leetcode.com/problems/task-scheduler)|
|27|Medium|[Minimum Number of Arrows to Burst Balloons](https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons)|
|28|Medium|[K Closest Points to Origin](https://leetcode.com/problems/k-closest-points-to-origin)|
|29|Medium|[Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements)|
|30|Medium|[Sort Characters By Frequency](https://leetcode.com/problems/sort-characters-by-frequency)|
|31|Medium|[Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array)|
|32|Medium|[Reorganize String](https://leetcode.com/problems/reorganize-string)|
|33|Medium|[Longest Subarray of 1's After Deleting One Element](https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element)|
|34|Hard|[Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists)|
|35|Hard|[Smallest Range Covering Elements from K Lists](https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists)|
|36|Hard|[Employee Free Time](https://leetcode.com/problems/employee-free-time)|
|37|Hard|[Rearrange String k Distance Apart](https://leetcode.com/problems/rearrange-string-k-distance-apart)|
|38|Hard|[Course Schedule III](https://leetcode.com/problems/course-schedule-iii)|
|39|Hard|[Maximum Frequency Stack](https://leetcode.com/problems/maximum-frequency-stack)|
|40|Hard|[Find Median from Data Stream](https://leetcode.com/problems/find-median-from-data-stream)|
|41|Hard|[Sliding Window Median](https://leetcode.com/problems/sliding-window-median)|
