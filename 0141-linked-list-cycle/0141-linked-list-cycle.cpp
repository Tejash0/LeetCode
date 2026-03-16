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
        while(temp && temp->next)
        {
            if(temp == head)
                return true;
            head = head->next;
            temp = temp->next->next;

        }
        return false;
    }   
};