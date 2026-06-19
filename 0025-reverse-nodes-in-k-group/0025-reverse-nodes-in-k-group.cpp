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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k <= 1)
            return head;
        int n = 0;
        ListNode *temp = head;
        ListNode *c1= nullptr;
        ListNode* c2 = nullptr;
        ListNode* mem = head;
        int count = 0;
        while(temp != nullptr)
        {
            n++;
            temp = temp->next;
        }
        n/=k;
        temp = head;
        while(temp!=nullptr)
        {
            if(n<1)
            {
                break;
            }
            c1 = temp;
            temp = temp->next;
            c1->next = c2;
            c2=c1;
            count++;
            if(count == k)
            {
                if(mem == head)
                {
                    head = c2;
                }
                else
                {
                    c1 = mem->next;
                    mem->next = c2;
                    mem = c1;
                }
                mem->next = temp;
                c2 = nullptr;
                count = 0;
                n--;
            }
        }
        return head;
    }
};
