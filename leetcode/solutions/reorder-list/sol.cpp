// Problem: https://leetcode.com/problems/reorder-list/

// O(n) time, O(1) space solution

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
private:
    ListNode* getNextToMiddleNode(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        // [1, 2, 3, 4, 5, NULL] will return 4
        // [1, 2, 3, 4, 5, 6, NULL] will also return 4
        ListNode *fast = head, *slow = head;
        while (fast -> next != NULL && fast -> next -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        // Break the list into two parts, and return the second half
        ListNode *temp = slow -> next;
        slow -> next = NULL;
        return temp;

    }
private:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) {
            return head;
        }

        ListNode *before = head, *current = head -> next;
        head -> next = NULL;

        while (current != NULL) {
            ListNode *temp = current -> next;
            current -> next = before;
            before = current;
            current = temp;
        }

        return before;
    }
public:
    void reorderList(ListNode* head) {
        if (head == NULL) {
            return;
        }

        ListNode *next_to_middle = getNextToMiddleNode(head);
        ListNode *head_of_other_list = reverseList(next_to_middle);

        ListNode *l1 = head, *l2 = head_of_other_list;
        // Merge these lists alternately
        // First node of l1, then first node of l2
        // Then second of l2, then second of l2 ... and so on
        while (l2 != NULL) {
            ListNode *temp = l1 -> next;
            l1 -> next = l2;
            l1 = temp;

            temp = l2 -> next;
            l2 -> next = l1;
            l2 = temp;
        }
    }
};