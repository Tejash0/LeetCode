class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map <int, int> map;
        for(auto i : nums)
        {
            map[i]++;
        }
        vector<pair<int, int>> un(map.begin(), map.end());
        sort(un.begin(),un.end(),[](const auto& a, const auto& b)
        {
            return a.second > b.second;
        });
        for(int i = 0; i< k;i++)
        {
            int x = un[i].first;
            ans.push_back(x);
        }
        return ans; 
    }
};