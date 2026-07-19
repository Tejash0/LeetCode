class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.empty())return 0;
        priority_queue<int> max_heap;
        for(int n:stones)max_heap.push(n);
        while(max_heap.size()>1)
        {
            int x = max_heap.top();
            max_heap.pop();
            int y = max_heap.top();
            max_heap.pop();
            if(x != y)
            {
                max_heap.push(x-y);
            }
        }
        return max_heap.empty() ? 0:max_heap.top();
    }
};
