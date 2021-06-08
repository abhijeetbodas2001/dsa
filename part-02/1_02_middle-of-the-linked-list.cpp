// Problem: https://leetcode.com/problems/middle-of-the-linked-list/

// O(n) time, O(1) space
// Ez

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
    ListNode* middleNode(ListNode* head) {
        // If there are two middle elements, this will return the **second** middle element.
		ListNode *fast = head, *slow = head;
		while (fast != NULL && fast -> next != NULL) {
			slow = slow -> next;
			fast = fast -> next -> next;
		}
		return slow;
    }
};