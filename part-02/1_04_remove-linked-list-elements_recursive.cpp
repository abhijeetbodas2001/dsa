// Problem: https://leetcode.com/problems/remove-linked-list-elements/

// O(n) time, O(n) space.
// Recursive solution.

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
		if (head == NULL) {
			return head;
		}
		
		if (head -> val != val) {
			// `head` should be included in the list. Join the filtered suffix
			// to `head` and return `head`.
			head -> next = removeElements(head -> next, val);
			return head;
		} else {
			// `head` should be excluded from the list, so return the filtered
			// suffix.
			return removeElements(head -> next, val);
		}
    }
};