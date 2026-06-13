class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs[0][0] == '\0')
        {
            return "";
        }
                
        vector<int> pre;

        string ans;
        int x = 0;
        for(auto i= 0; i < strs[0].length();i++)
        {
            pre.push_back(0);
        }
        for(auto i= 0; i < strs.size();i++)
        {
            for(auto j = 0; j < pre.size();j++)
            {
                if(strs[0][j] == strs[i][j])
                {
                    pre[j]++;
                }
            }
        }
       
        if(pre[x] < strs.size())
        {
            return "";
        }
        bool check = true;
        while(check)
        {
            if(x < pre.size() && pre[x] == strs.size())
            {
                ans.push_back(strs[0][x]);
                x++;
            }
            else
            {
                check = false;
            }
        } 
        return ans;
    }
};