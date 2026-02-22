class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> ans;
        int curr=0,max=0;
        for(auto i:nums)
        {
            ans.insert(i);
        }
        for(auto i:ans)
        {
            curr=0;
            if(ans.find(i-1) == ans.end())
            {
                while(ans.find(i+curr) != ans.end())
                {
                    curr++;
                }
                if(max<curr)
                {
                    max=curr;
                }
            }
        }
        return max;
    }
};