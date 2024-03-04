## Contents

This part contains problems on these topics:
- Fast and slow pointers
- In-place reversal of linked list
- Two pointers

## Notes

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

|Serial number|Difficulty|Problem|Solution(s)|
|-|-|-|-|
|01|Easy|[Linked List Cycle](https://leetcode.com/problems/linked-list-cycle)|
|02|Easy|[Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list)|
|03|Easy|[Reverse Linked List](https://leetcode.com/problems/reverse-linked-list)|
|04|Easy|[Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list)|
|05|Easy|[Remove Linked List Elements](https://leetcode.com/problems/remove-linked-list-elements)|
|06|Easy|[Remove Duplicates from Sorted List](https://leetcode.com/problems/remove-duplicates-from-sorted-list)|
|07|Easy|[Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists)|
|08|Easy|[Two Sum](https://leetcode.com/problems/two-sum)|
|09|Easy|[Squares of a Sorted Array](https://leetcode.com/problems/squares-of-a-sorted-array)|
|10|Easy|[Backspace String Compare](https://leetcode.com/problems/backspace-string-compare)|
|11|Easy|[Move Zeroes](https://leetcode.com/problems/move-zeroes)|
|12|Easy|[Is Subsequence](https://leetcode.com/problems/is-subsequence)|
|13|Medium|[Find the Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number)|
|14|Medium|[Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii)|
|15|Medium|[Add Two Numbers](https://leetcode.com/problems/add-two-numbers)|
|16|Medium|[Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list)|
|17|Medium|[Sort List](https://leetcode.com/problems/sort-list)|
|18|Medium|[Reorder List](https://leetcode.com/problems/reorder-list)|
|19|Medium|[Reverse Linked List II](https://leetcode.com/problems/reverse-linked-list-ii)|
|20|Medium|[Rotate List](https://leetcode.com/problems/rotate-list)|
|21|Medium|[Swap Nodes in Pairs](https://leetcode.com/problems/swap-nodes-in-pairs)|
|22|Medium|[Odd Even Linked List](https://leetcode.com/problems/odd-even-linked-list)|
|23|Medium|[3Sum](https://leetcode.com/problems/3sum)|
|24|Medium|[3Sum Closest](https://leetcode.com/problems/3sum-closest)|
|25|Medium|[Subarray Product Less Than K](https://leetcode.com/problems/subarray-product-less-than-k)|
|26|Medium|[Sort Colors](https://leetcode.com/problems/sort-colors)|
|27|Medium|[Container With Most Water](https://leetcode.com/problems/container-with-most-water)|
|28|Hard|[Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group)|
|29|Hard|[Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water)|
