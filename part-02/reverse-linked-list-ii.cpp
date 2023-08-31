// Problem: https://leetcode.com/problems/reverse-linked-list-ii/

// O(n) time, O(1) space
// The reverse linked list problem, with a twist
// Dry run till the last step (V.V. Imp)

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) {
            // There is nothing to reverse
            return head;
        }

        ListNode *left_node = head, *right_node = head;
        ListNode *before = new ListNode(-1, head);
        ListNode *orig_before = before;

        // Headstart to `right_node`
        for (int i = 0; i < (right - left); i++) {
            right_node = right_node -> next;
        }

        for (int i = 0; i < left - 1; i++) {
            left_node = left_node -> next;
            right_node = right_node -> next;
            before = before -> next;
        }

        // Now, if we're given [1, 2, 3, 4, 5, 6], left = 3 and right = 5, then
        // `before` should be at 2, `left_node` should be at 3, and `right_node` should be 5.
        ListNode *current = left_node;
        while (current != right_node) {
            ListNode *temp = current -> next;

            if (current == left_node) {
                // Specially handle the `left_node` and join it to `right_node -> next`
                current -> next = right_node -> next;
                before -> next = right_node;
            } else {
                current -> next = before;
            }

            before = current;
            current = temp;
        }

        // NOTE! This is important, because the loop did not handle setting `right_node` correctly.
        // Dry run to understand
        current -> next = before;

        // Don't return `head` here!
        return orig_before -> next;
    }
};