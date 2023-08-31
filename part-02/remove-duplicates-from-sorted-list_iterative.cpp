// Problem: https://leetcode.com/problems/remove-duplicates-from-sorted-list/

// O(n) time, O(1) space
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
    ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL) {
			return head;
		}

        ListNode* fakeHead = new ListNode(-101, head);
		ListNode* before = fakeHead;
		ListNode* current = head;
		
		// `before` travels the filtered list. `current` travles the whole list.
		while (current -> next != NULL) {
			if (current -> val == current -> next -> val) {
				before -> next = current -> next;
			} else {
				before = current;
			}
			
			// Move `current` ahead.
			current = current -> next;
		}
		
		return fakeHead -> next;
    }
};