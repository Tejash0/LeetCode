class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, int> map;
        int num = 0;
        string s;
        if(strs.size() < 2)
        {
            ans.push_back({strs[0]});
            return ans;
        }
        for(int i = 0; i < strs.size(); i++)
        {
            s = strs[i];
            sort(s.begin(), s.end());
            if(map.find(s) == map.end())
            {
                map.insert({s, num});
                num++;
                ans.push_back({strs[i]});
            }
            else
            {
                ans[map[s]].push_back(strs[i]);
            }
        }
        return ans;
    }
};
