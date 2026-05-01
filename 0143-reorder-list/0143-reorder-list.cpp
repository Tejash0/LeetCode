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

        ListNode* second;
        second = slow->next;
        slow->next = NULL;
        ListNode* prev = NULL;
        ListNode* temp;
        while(second != NULL)
        {
            temp = second;
            second = second->next;
            temp->next = prev;
            prev = temp;
        }

        while(prev != NULL)
        {
            temp = head->next;
            head->next = prev;
            head = temp;
            temp = prev->next;
            prev->next = head;
            prev = temp;
        }
    }
};