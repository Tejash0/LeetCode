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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head = NULL;
        ListNode *temp = NULL;
        while(list1 && list2)
        {
            if(list1->val < list2->val)
            {
                if(!head && !temp)
                {
                    head = list1;
                    temp = list1;
                    list1 = list1->next;
                }
                else
                {
                    temp->next = list1;
                    temp = list1;
                    list1 = list1->next;
                }
            }
            else if(list1->val > list2->val)
            {
                if(!head && !temp)
                {
                    head = list2;
                    temp = list2;
                    list2 = list2->next;
                }
                else
                {
                    temp->next = list2;
                    temp = list2;
                    list2 = list2->next;
                }
            }
            else
            {
                if(!head && !temp)
                {                    
                    head = list1;
                    temp = list1;
                    list1 = list1->next;
                    temp->next = list2;
                    temp = list2;
                    list2 = list2->next; 
                }
                else
                {
                    temp->next = list1;
                    temp = list1;
                    list1 = list1->next;
                    temp->next = list2;
                    temp = list2;
                    list2 = list2->next;
                }
            }
        }
        if(!list1)
        {    
            if(!head)
                head = list2;
            else
            temp->next = list2;
        }
        else if(!list2)
        {
            if(!head)
                head = list1;
            else
                temp->next = list1;
        }
        return head;
    }
};
