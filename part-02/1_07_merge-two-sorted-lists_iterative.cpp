// Problem: https://leetcode.com/problems/merge-two-sorted-lists/

// O(n) time, O(1) space iterative solution.

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
            return l2;
        } else if (l2 == NULL) {
            return l1;
        }

        ListNode* head = l1 -> val <= l2 -> val ? l1 : l2;
        ListNode* merged = new ListNode(0); // dummy
        while (true) {
            if (l1 == NULL) {
                merged -> next = l2;
                break;
            } else if (l2 == NULL) {
                merged -> next = l1;
                break;
            }

            if (l1 -> val <= l2 -> val) {
                merged -> next = l1;
                l1 = l1 -> next;
            } else {
                merged -> next = l2;
                l2 = l2 -> next;
            }
            merged = merged -> next;
        }

        return head;
    }
};