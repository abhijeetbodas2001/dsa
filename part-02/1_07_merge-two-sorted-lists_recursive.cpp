// Problem: https://leetcode.com/problems/merge-two-sorted-lists/

// O(n) time, O(n) space recursive solution.

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
        ListNode* temp;

        // Swap l1 and l2 to make sure l1's head always has the smaller value
        // (and so should be processed).
        if (l1 -> val > l2 -> val) {
            temp = l2;
            l2 = l1;
            l1 = temp;
        }

        temp = l1 -> next;
        l1 -> next = mergeTwoLists(temp, l2);
        return l1;
    }
};