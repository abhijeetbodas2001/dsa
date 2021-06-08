// Problem: https://leetcode.com/problems/reverse-linked-list/

// O(n) time, O(1) space.
// Iterative solution

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
			return head;
		}
		
		ListNode* before = NULL;
		ListNode* after;
		
		while (head != NULL) {	// Doing head -> next != NULL will skip the last element :)
			// This is easy. Use pen-paper and go stepwise.
			after = head -> next;
			head -> next = before;
			before = head;
			head = after;
		}
		
		// `head` is NULL now, and `before` will store the first element of the reversed
		// list.
		return before;
    }
};