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
        ListNode* reverseList(ListNode* head) {
            ListNode *temp1 = NULL;
            ListNode *temp2 = NULL;
            while(head != NULL)
            {
                if(head->next == NULL)
                {
                    temp2=head;
                    head->next=temp1;
                    return head;
                }
                temp2=head;
                head=head->next;
                temp2->next=temp1;
                temp1=temp2;
            }   
            return head;     
        }
};