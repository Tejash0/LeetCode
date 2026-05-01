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
        ListNode *ptr = head;
        ListNode *temp = head;
        bool check = true;
    
        while(check == true)
        {
            if(head == NULL || head->next == NULL)
                return;
            if(head->next == NULL)
                return;
            if(ptr->next != NULL)
            {
                temp = ptr;
                ptr = ptr->next;
            }
            else if(ptr->next == NULL)
            {
                temp->next = NULL;
                temp = head->next;
                head->next = ptr;
                ptr->next = temp;
                head = temp;
                ptr = temp;
            }
        } 
    }
};