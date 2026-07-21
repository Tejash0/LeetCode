class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
       unordered_map<char,int> freq;
       priority_queue<int> max_heap;
       queue<pair<int,int>> q;

       for(char i : tasks)freq[i]++;
       for(auto i : freq)max_heap.push(i.second);
       int time = 0;
       
       while(!max_heap.empty() || !q.empty())
       {
            time++;
            if(!max_heap.empty())
            {
                auto i = max_heap.top();
                max_heap.pop();
                i--;
                if(i>0)q.push({i,time+n});
            }
            if(!q.empty() && q.front().second == time)
            {
                max_heap.push(q.front().first);
                q.pop();
            }
       }
       return time;
    }
};
