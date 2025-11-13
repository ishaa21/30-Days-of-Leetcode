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
        // Step 1: Dummy node before head
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* first = dummy;
        ListNode* second = dummy;

        // Step 2: Move first pointer n+1 steps ahead
        for (int i = 0; i <= n; ++i) {
            first = first->next;
        }

        // Step 3: Move both until first reaches the end
        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }

        // Step 4: Remove the nth node
        ListNode* nodeToDelete = second->next;
        second->next = second->next->next;
        delete nodeToDelete; // Free memory

        return dummy->next; // Return new head
    }
};
