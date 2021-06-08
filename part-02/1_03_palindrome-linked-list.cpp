// Problem: https://leetcode.com/problems/palindrome-linked-list/

// O(n) time, O(1) space.
// Idea is to reverse the second half of the linked list, and then
// compare with the elements in the first half.

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
private:
	ListNode* reverseList(ListNode* head) {
		// COPIED FROM REVERSE-LINKED-LIST PROBLEM
		if (head == NULL) {
			return head;
		}
		
		ListNode* before = NULL;
		ListNode* after;
		while (head != NULL) {
			after = head -> next;
			head -> next = before;
			before = head;
			head = after;
		}

		return before;
    }
	
	ListNode* getMiddleNode(ListNode* head) {
		// If there are two middle elements, this will return the **second** middle element.
		ListNode *fast = head, *slow = head;
		while (fast != NULL && fast -> next != NULL) {
			slow = slow -> next;
			fast = fast -> next -> next;
		}
		return slow;
	}
	
	int getLength(ListNode* head) {
		int len = 0;
		while (head != NULL) {
			len++;
			head = head -> next;
		}
		return len;
	}
	
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head -> next == NULL) {
			return true;
		}
		
		int len = getLength(head);
		ListNode* middle = getMiddleNode(head);
		
		ListNode *a = head;
		ListNode *b = reverseList(middle);
		
		for (int i = 0; i < len / 2; i++) {
			if (a -> val != b -> val) {
				return false;
			}
			
			a = a -> next;
			b = b-> next;
		}
		
		return true;
		
    }
};