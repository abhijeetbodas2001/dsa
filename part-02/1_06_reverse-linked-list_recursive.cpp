// Problem: https://leetcode.com/problems/reverse-linked-list/

// O(n) time, O(n) space
// Recursive solution

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
    ListNode* reverseList(ListNode* head) {
		if (head == NULL) {
			// urghhh
			return head;
		}

        if (head -> next == NULL) {
			return head;
		}
		
		// Store the element coming after `head`.
		ListNode* after = head -> next;
		
		// Assume `reverseList` returns the correct head of the reverse of the list
		// starting at `after`.
		ListNode* reversed_after = reverseList(after);
		
		// `after` should be the end of the reversed sublist now.
		assert(after -> next == NULL);
		
		// Join `head` to the end of the reversed sublist.
		after -> next = head;
		
		// Make `head` the end of the sublist.
		head -> next = NULL;
		
		// Return the "head" of the sublist.
		return reversed_after;
    }
};