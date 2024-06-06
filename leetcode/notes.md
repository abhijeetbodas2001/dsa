# Part 1

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

# Part 2

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

# Part 3

## Contents

This part contains problems on these topics:
- BFS
- DFS
- Graph


## Algorithms

- [In-order iterative DFS](/vanilla-algorithms/iterative_in-order_dfs.cpp)
- [Breadth first search](/vanilla-algorithms/bfs.cpp)

## Notes

- For BST, the best solution one can get is usually `O(h)` time (not `O(N)`),
so try to get to that. In-order traversals are great for BST's.

- For tracking max, min values, use pointers/pass-by-reference in recursive functions.
No need to block the return value for this.

- Path-dependent problems are difficult to solve iteratively. You need to attach some data for
the path on each node in the stack, which can blow up the space complexity. Best to do recursively.
Example:
    - Path sums
    - Finding cycles in directed graphs (need to search in recursion stack)

- If it is difficult to backtrack using recursion, it may be usefult to save the parents of each
node in a map/vector and then go from the leaf to the root. See "minimum height trees" longest path
solution for an example

# Part 4

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
