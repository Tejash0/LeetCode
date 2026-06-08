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
        ListNode* temp = head;
        ListNode* t2 = head;
        int co = 1;
        while(true)
        {
            if(head->next == NULL)
            {
                head = NULL;
                return head;
            }
            temp = temp->next;
            co++;
            if(temp->next == NULL)
            {
                if(co == n)
                {
                    head = head->next;
                    return head;
                }
                while(true)
                {
                    if( co == n+1)
                    {
                        if(t2->next->next == NULL || t2->next == NULL)
                        {
                            t2->next = NULL;
                            return head;
                        }
                        t2->next = t2->next->next;
                        return head;
                    }
                    t2 = t2->next;
                    co--;
                }
            }
        }
        return head;
    }
};