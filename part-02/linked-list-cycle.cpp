// Problem: https://leetcode.com/problems/linked-list-cycle/

// O(n) time, O(1) space
// Fast and slow pointers
// Logic -> If there is a loop, the fast and the slow pointers
// will definitely meet.
// https://www.geeksforgeeks.org/how-does-floyds-slow-and-fast-pointers-approach-work/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL) {
			return false;
		}
		
		ListNode* fast = head;
		ListNode* slow = head;
		
		while (fast != NULL && fast -> next != NULL) {			
			slow = slow -> next;
			fast = fast -> next -> next;
			
			if (fast == slow) {
				return true;
			}
		}
		
		return false;
    }
};