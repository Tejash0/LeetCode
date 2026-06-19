class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i = 0,j = 0;
        priority_queue<pair<int,int>> c;
        vector<int> ans;
        while(j<nums.size())
        {
            if(!c.empty() && c.top().first < nums[j])
            {
                c = priority_queue<pair<int,int>>();
                c.push({nums[j],j});
            }
            c.push({nums[j],j});
            if(j-i+1 >= k)
            {
                while(c.top().second < i)
                {
                    c.pop();
                }
                if(c.top().second == i)
                {
                    ans.push_back(nums[i]);
                    c.pop();
                    i++;  
                }
                else
                {
                    ans.push_back(c.top().first);
                    i++;
                }
            }
            j++;
            
        }
        return ans;
    }
};