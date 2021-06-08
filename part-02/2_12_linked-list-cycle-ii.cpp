// Problem: https://leetcode.com/problems/linked-list-cycle-ii/

// Tort-Hare algorithm
// See https://leetcode.com/problems/find-the-duplicate-number/solution/

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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }

        ListNode *tort = head, *hare = head, *copy = head;
        while (true) {
            tort = tort -> next;
            if (tort == NULL) {
                return NULL;
            }

            hare = hare -> next;
            if (hare == NULL) {
                return NULL;
            }
            hare = hare -> next;
            if (hare == NULL) {
                return NULL;
            }

            if (tort == hare) {
                break;
            }
        }

        tort = copy;
        while (tort != hare) {
            tort = tort -> next;
            hare = hare -> next;
        }

        return tort;
    }
};