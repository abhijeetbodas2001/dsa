// Problem: https://leetcode.com/problems/odd-even-linked-list/

// O(n) time, O(1) space
// Simulation

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
    ListNode* oddEvenList(ListNode* head) {
        // The "odd" and "even" here are for array-like indices
        // For example, [1, 5, 9], 1 and 9 are "even" (index 0 and 2)

        if (head == NULL || head -> next == NULL || head -> next -> next == NULL) {
            // Lengths 0, 1, 2 don't need processing
            return head;
        }
        ListNode *dummy_odd = new ListNode(-1, head);
        ListNode *dummy_even = new ListNode(-1, dummy_odd);

        ListNode *current = head;
        ListNode *first_odd = head -> next;
        ListNode *before_even = dummy_even, *before_odd = dummy_odd;
        while (true) {
            before_even -> next = current;
            before_odd -> next = current -> next;

            if (current -> next == NULL || current -> next -> next == NULL) {
                // Connect end of even list to start of odd list.
                current -> next = first_odd;
                break;
            }

            current = current -> next -> next;
            before_even = before_even -> next;
            before_odd = before_odd -> next;
        }

        return head;
    }
};