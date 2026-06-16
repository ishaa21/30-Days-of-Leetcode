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
    bool isPalindrome(ListNode* head) {

        if(head == NULL || head->next == NULL)
            return true;

            
        ListNode* start = head;
        ListNode* ptr = head;
        ListNode* preptr = NULL;


        while(ptr && ptr->next)
        {
            preptr = start;
            start = start->next;
            ptr = ptr->next->next;
        }

        if(ptr != NULL)
            start = start->next;

        preptr->next = NULL;

        ListNode* prev = NULL;
        ListNode* curr = start;

        while(curr)
        {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        ListNode* first = head;
        ListNode* second = prev;

        while(first && second)
        {
            if(first->val != second->val)
            {
                return false;
            }

            first = first->next;
            second = second->next;
        }

        return true;
    }
};