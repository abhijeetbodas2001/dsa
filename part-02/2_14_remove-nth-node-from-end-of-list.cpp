// Problem: https://leetcode.com/problems/remove-nth-node-from-end-of-list/

// O(n) time, O(1) space, single pass
// An obvious solution is to, in a first pass, find the length
// of the linked list, and in a second pass, count the steps taken
// and when you reach the (len - n)th step, so the deletion.

// This solution does the deletion in a single pass, without explicitly
// finding the length of the list, using two pointers.

// The `dummy` node handles cases where we are required to delete the first
// node of the list etc.

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy, *before, *slow, *fast;
        dummy = new ListNode(-1, head);
        before = dummy;
        slow = head;
        fast = head;

        // Give a headstart to `fast` of `n` steps
        while (n > 0) {
            assert(fast != NULL);
            fast = fast -> next;
            n--;
        }

        // When `fast` reaches the end of the list, `slow` would be `n` steps beind
        while (fast != NULL) {
            before = slow;
            slow = slow -> next;
            fast = fast -> next;
        }

        assert(slow != NULL);
        before -> next = slow -> next;

        return dummy -> next;
    }
};