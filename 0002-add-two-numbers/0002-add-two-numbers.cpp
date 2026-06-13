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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        struct ListNode* ans;
        struct ListNode* head = NULL;
        head = createnode(0);
        ans = head;
        
        int carry = 0;
        while(l1 != NULL || l2 != NULL)
        {
            if(l1 == NULL)
            {
                if(l2->val+carry <= 9)
                {
                    ans->val = l2->val+carry;
                    carry = 0;
                }
                else if( l2->val+carry > 9)
                {
                    ans->val = (l2->val+carry)%10;
                    carry = 1;
                }
                l2 = l2->next;
                if(l1 == NULL && l2 == NULL)
                {
                    if(carry == 1)
                    {
                        ans->next = createnode(carry);
                    }
                    ans = head;
                    return ans;
                }
                ans->next = createnode(0);
                ans = ans->next;
                
            }
            else if(l2 == NULL)
            {
                if(l1->val+carry <= 9)
                {
                    ans->val = l1->val+carry;
                    carry = 0;
                }
                else if(l1->val+carry > 9)
                {
                    ans->val = (l1->val+carry)%10;
                    carry = 1;
                }
                l1 = l1->next;
                if(l1 == NULL && l2 == NULL)
                {
                    if(carry == 1)
                    {
                        ans->next = createnode(carry);
                    }
                    ans = head;
                    return ans;
                }
                ans->next = createnode(0);
                ans = ans->next;
                
            }
            else
            {
                if(l1->val + l2->val + carry <= 9)
                {
                    ans->val = l1->val + l2->val + carry;
                    carry = 0;
                }
                else if(l1->val + l2->val + carry > 9)
                {
                    ans->val = (l1->val + l2->val + carry)%10;
                    carry = 1;
                }
                
                l1 = l1->next;
                l2 = l2->next;
                if(l1 == NULL && l2 == NULL)
                {
                    if(carry == 1)
                    {
                        ans->next = createnode(carry);
                    }
                    ans = head;
                    return ans;
                }
                ans->next = createnode(0);
                ans = ans->next;
            }
        }
        ans = head;
        return ans;
    }
    ListNode* createnode(int data) {
        struct ListNode* newnode = new ListNode();
        newnode->val = data;
        newnode->next = NULL;
        return newnode;
    }
};