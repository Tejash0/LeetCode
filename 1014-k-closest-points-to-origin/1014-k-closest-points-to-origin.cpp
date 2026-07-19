class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
       priority_queue<pair<double,vector<int>>> max_heap;
       for(vector<int> i:points)
       {
            double x = pow(i[0],2) + pow(i[1],2);
            x = sqrt(x);
            max_heap.push({x,i});
            if(max_heap.size()>k)max_heap.pop();
       }
       vector<vector<int>> ans;
        while(!max_heap.empty())
        {
            ans.push_back(max_heap.top().second);
            max_heap.pop();
        } 
        return ans;   
    }
};
