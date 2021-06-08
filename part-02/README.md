- As a general rule, whenever you are about to change the `next` of some element,
be sure to store the original `next` in some (temporary) variable.
- Recursive solutions are `O(n)` space anyways, because of stack space.
- To handle edge cases, it is frequntly useful to create a "dummy" node like so:
	```
	ListNode* dummy = new ListNode(0);
	dummy -> next = head
	```
	
- Finding nodes in a single pass using two pointers: If there is a relation given between the node to be found
and the end of the list, create to pointers and make it so that as the `fast` reaches the end, the `slow` reaches
the node to be found. For example:
	- If middle node is to be found, make the `fast` travel two times as fast as `slow`
	- If nth node from end to be found, maintain a distance of `n` between `fast` and `slow`
- For border cases, always return `head`, not `NULL`. Example:
	```
	if (head == NULL) {
		return head;
	}
	```
	(Don't do `return NULL;`)

## Some helper methods

```
ListNode* reverseList(ListNode* head) {
	if (head == NULL) {
		return head;
	}

	ListNode *before = head, *current = head -> next;
	head -> next = NULL;

	while (current != NULL) {
		ListNode *temp = current -> next;
		current -> next = before;
		before = current;
		current = temp;
	}

	return before;
}

ListNode* getMiddleNode(ListNode* head) {
	if (head == NULL) {
		return NULL;
	}
	// For [1, 2, 3, 4, 5] will return 3
    // For [1, 2, 3, 4, 5, 6] will return 3
	ListNode *fast = head, *slow = head;
	while (fast -> next != NULL && fast -> next -> next != NULL) {
		slow = slow -> next;
		fast = fast -> next -> next;
	}
	return slow;
}

ListNode* getLength(ListNode* head) {
	int len = 0;
	while (head != NULL) {
		len++;
		head = head -> next;
	}
	return len;
}
```

## Problems

|Serial number|Difficulty|Problem|Solution(s)|Date|
|-|-|-|-|-|
|01|Easy|[Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/)|[Solution](/part-02/1_01_linked-list-cycle.cpp)|Done|
|02|Easy|[Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list/)|[Solution](/part-02/1_02_middle-of-the-linked-list.cpp)|Done|
|03|Easy|[Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/)|[Solution](/part-02/1_03_palindrome-linked-list.cpp)|Done|
|04|Easy|[Remove Linked List Elements](https://leetcode.com/problems/remove-linked-list-elements/)|[Solution (recursive)](/part-02/1_04_remove-linked-list-elements_recursive.cpp), [Solution (iterative)](/part-02/1_04_remove-linked-list-elements_iterative.cpp)|Done|
|05|Easy|[Remove Duplicates from Sorted List](https://leetcode.com/problems/remove-duplicates-from-sorted-list/)|[Solution (iterative)](/part-02/1_05_remove-duplicates-from-sorted-list_iterative.cpp), [Solution (recursive)](/part-02/1_05_remove-duplicates-from-sorted-list_recursive.cpp)|Done|
|06|Easy|[Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/)|[Solution (recursive)](/part-02/1_06_reverse-linked-list_recursive.cpp), [Solution (iterative)](/part-02/1_06_reverse-linked-list_iterative.cpp)|Done|
|07|Easy|[Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)|[Solution (recursive)](/part-02/1_07_merge-two-sorted-lists_recursive.cpp), [Solution (iterative)](/part-02/1_07_merge-two-sorted-lists_iterative.cpp)|Done|
|08|Easy|[Two Sum](https://leetcode.com/problems/two-sum/)|[Solution](/part-02/1_08_two-sum.cpp)|Done|
|09|Easy|[Squares of a Sorted Array](https://leetcode.com/problems/squares-of-a-sorted-array/)|[Solution](/part-02/1_09_squares-of-a-sorted-array.cpp)|Done|
|10|Easy|[Backspace String Compare](https://leetcode.com/problems/backspace-string-compare)|[Solution (O(1) space, does not work)](/part-02/1_10_backspace-string-compare.cpp)|Tried once|
|11|Medium|[Find the Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number/)|[Solution](/part-02/2_11_find-the-duplicate-number.cpp)|Done|
|12|Medium|[Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii/)|[Solution](/part-02/2_12_linked-list-cycle-ii.cpp)|Done|
|13|Medium|[Add Two Numbers](https://leetcode.com/problems/add-two-numbers/)|[Solution](/part-02/2_13_add-two-numbers.cpp)|Done|
|14|Medium|[Remove Nth Node From End Of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)|[Solution (single pass)](/part-02/2_14_remove-nth-node-from-end-of-list.cpp)|Done|
|15|Medium|[Sort List](https://leetcode.com/problems/sort-list/)|[Solution (TODO)](/part-02/2_15_sort-list.cpp)|20210610|
|16|Medium|[Reorder List](https://leetcode.com/problems/reorder-list/)|[Solution](/part-02/2_16_reorder-list.cpp)|Done|
|17|Medium|[Reverse Linked List II](https://leetcode.com/problems/reverse-linked-list-ii/)|[Solution](/part-02/2_17_reverse-linked-list-ii.cpp)|Done|
|18|Medium|[Rotate List](https://leetcode.com/problems/rotate-list/)|[Solution](/part-02/2_18_rotate-list.cpp)|Done|
|19|Medium|[Swap Nodes in Pairs](https://leetcode.com/problems/swap-nodes-in-pairs/)|[Solution](/part-02/2_19_swap-nodes-in-pairs.cpp)|Done|
|20|Medium|[Odd Even Linked List](https://leetcode.com/problems/odd-even-linked-list/)|[Solution](/part-02/2_20_odd-even-linked-list.cpp)|Done|
|21|Medium|[3 Sum](https://leetcode.com/problems/3sum/)|[Solution (binary search)](/part-02/2_21_3-sum_binary-search.cpp), [Solution (Hash map, does not work)](/part-02/2_21_3-sum_hash-map.cpp)|20210617|
|22|Medium|[3 Sum Closest](https://leetcode.com/problems/3sum-closest/)|[Solution](/part-02/2_22_3-sum-closest.cpp)|Done|
|23|Medium|[Subarrays with Product Less than K](https://leetcode.com/problems/subarray-product-less-than-k/)|[Solution](/part-02/2_23_subarrays-with-product-less-than-k.cpp)|20210617|
|24|Medium|[Sort Colours](https://leetcode.com/problems/sort-colors/)|[Solution](/part-02/2_24_sort-colours.cpp)|20210617|
|25|Medium|[Container With Most Water](https://leetcode.com/problems/container-with-most-water/)|[Solution](/part-02/2_25_container-with-most-water.cpp)|20210617|
|26|Hard|[Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group/)|[Solution](/part-02/3_26_reverse-nodes-in-k-group.cpp)|202106|
|27|Hard|[Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/)|[Solution](/part-02/3_27_trapping-rain-water.cpp)|202106|
