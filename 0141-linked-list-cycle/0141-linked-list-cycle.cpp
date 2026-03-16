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
        if(head == NULL)
            return false;
        unordered_set<ListNode*> check;
        ListNode* temp;
        temp = head;
        while(temp->next != NULL)
        {
            if(check.find(temp) != check.end())
                return true;
            else
            {
                check.insert(temp);
                temp = temp->next;
            }
        } 
        return false;
    }
};