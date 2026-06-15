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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next) return nullptr;

        ListNode* start = head;
        ListNode* ptr = head;
        ListNode* preptr = nullptr;

        while(start && start->next)
        {
            preptr = ptr;
            ptr = ptr->next;
            start = start->next->next;
        }

        ListNode* next = ptr->next;
        preptr->next = next;

        return head;
    }
};