class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i = 0,j = 0;
        deque<int> c;
        vector<int> ans;
        while(j<nums.size())
        {
                while(!c.empty() && nums[c.back()] < nums[j])
                {
                    c.pop_back();
                }
                c.push_back(j);
            if(j-i+1 >= k)
            {
                if(c.front() < i)
                {
                    c.pop_front();
                }
                    ans.push_back(nums[c.front()]);
                    i++;
            }
            j++;
            
        }
        return ans;
    }
};