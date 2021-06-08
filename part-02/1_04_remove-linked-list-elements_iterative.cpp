// Problem: https://leetcode.com/problems/remove-linked-list-elements/

// O(n) time, O(1) space.
// Iterative solution.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
		// One could also create a "fake" `head`, and join it to the real `head`
		// to avoid this edge case.
		
		// There maybe a prefix of the list with all elements equal to `val`
		while (head != NULL && head -> val == val) {
			head = head -> next;
		}
		
		if (head == NULL) {
			// This is the case where all elements of the list were `val`. :(
			return head;
		}
		
		assert(head -> val != val);
		ListNode *before = head;
		ListNode *current = head -> next;
		
		// `current` traverses thorugh the original list, and `before` traverses only through
		// the filtered list.
		while (current != NULL) {
			if (current -> val == val) {
				// This is the "skip the element" logic. `before` stays as it was earlier.
				before -> next = current -> next;
			} else {
				before = current;
			}
			
			current = current -> next;
		}
		
		return head;
    }
};