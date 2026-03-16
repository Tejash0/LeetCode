/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head)
            return false;
        ListNode* temp = head->next;
        while(head && temp)
        {
            if(temp == head)
                return true;
            else if(temp->next == NULL)
                return false;
            head = head->next;
            temp = temp->next->next;

        }
        return false;
    }   
};