// Problem: https://leetcode.com/problems/remove-duplicates-from-sorted-list/

// O(n) time, O(n) space
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) {
			return head;
		}
		
		ListNode* after = deleteDuplicates(head -> next);
		if (after == NULL) {
			head -> next = after;
			return head;
		} else if (head -> val == after -> val) {
			return after;
		} else {
			// For a continuous interval of equal elements, we return the LAST
			// of that interval (as in the above condition). Hence, we need to join
			// the output to `head`.
			head -> next = after;	// Note!
			return head;
		}
    }
};