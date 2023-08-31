// Problem: https://leetcode.com/problems/swap-nodes-in-pairs/

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
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(-1, head);
        ListNode *current = head, *before = dummy;

        while (current != NULL && current -> next != NULL) {
            ListNode *temp = current -> next -> next;
            before -> next = current -> next;
            current -> next -> next = current;

            before = current;
            current = temp;
        }

        if (current == NULL) {
            before -> next = NULL;
        } else {
            before -> next = current;
        }

        // Don't return `head` here!
        return dummy -> next;
    }
};