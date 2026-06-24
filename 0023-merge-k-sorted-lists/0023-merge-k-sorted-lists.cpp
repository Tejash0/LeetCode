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
struct compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; // '>' creates a Min-Heap (smallest element on top)
    }
};
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare> min_h;
        ListNode head(0);
        ListNode* tail = &head;
        if(lists.empty())return {};
        if(lists.size()<1)return lists[0];
        for(ListNode* x : lists)
        {
            if(x!=nullptr)
                min_h.push(x);
        }
        while(!min_h.empty())
        {
            tail->next = min_h.top();
            min_h.pop();
            tail = tail->next;
            if(tail->next != nullptr)
                min_h.push(tail->next);
        }
        return head.next;
    }
};
