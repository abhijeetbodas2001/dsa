// Problem: https://leetcode.com/problems/add-two-numbers/

// O(n) time, O(n) space iterative solution.

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy, *before, *current;
        dummy = new ListNode(-1);
        before = dummy;
        int carry = 0;

        while (l1 != NULL || l2 != NULL) {
            int d1 = l1 == NULL ? 0 : l1 -> val;
            int d2 = l2 == NULL ? 0 : l2 -> val;
            int digits_sum = (d1 + d2 + carry);
            carry =  digits_sum / 10;

            // Create new digit in the answer list
            current = new ListNode(digits_sum % 10);
            before -> next = current;
            before = current;

            // Move pointers forward if not NULL
            l1 = l1 == NULL ? l1 : l1 -> next;
            l2 = l2 == NULL ? l2 : l2 -> next;
        }

        // This handles cases where there will be an increase in digits in final answer
        // Example: [1, 9] + [2, 7] = [3, 6, 1]
        if (carry == 1) {
            current = new ListNode(1);
            before -> next = current;
        }

        return dummy -> next;
    }
};