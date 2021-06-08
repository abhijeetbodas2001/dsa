// Problem: https://leetcode.com/problems/rotate-list/

// O(n) time, O(1) space solution
// No need to actually "rorate" the list. It is sufficient to change the links
// of the to-be last and first nodes

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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head -> next == NULL) {
            return head;
        }

        int len = 0;
        ListNode *copy = head;
        while (copy != NULL) {
            len++;
            copy = copy -> next;
        }

        int num_rot = k % len;
        if (num_rot == 0) {
            // No rotation
            return head;
        }

        ListNode *old_head = head, *old_last_node = head;
        while (old_last_node -> next != NULL) {
            old_last_node = old_last_node -> next;
        }

        ListNode *new_last_node = head;
        for (int i = 0; i < (len - 1 - num_rot); i++) {
            new_last_node = new_last_node -> next;
        }
        ListNode *new_head = new_last_node -> next;
        new_last_node -> next = NULL;
        old_last_node -> next = old_head;
        
        return new_head;
    }
};