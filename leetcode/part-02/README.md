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
