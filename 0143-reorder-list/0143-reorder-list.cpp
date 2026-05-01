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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast;
        if(head == NULL || head->next == NULL)
            return;
        fast = head->next;
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = NULL;
        ListNode* prev = NULL;
        while(fast != NULL)
        {
            slow = fast;
            fast = fast->next;
            slow->next = prev;
            prev = slow;
        }

        while(prev != NULL)
        {
            slow = head->next;
            head->next = prev;
            head = slow;
            slow = prev->next;
            prev->next = head;
            prev = slow;
        }
    }
};