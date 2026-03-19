class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int,int,std::greater<int>> buff;
        stack <int> ans;
        for(int i=0; i < speed.size();i++)
        {
            buff[position[i]] = speed[i];
        }
        
        for(auto i:buff)
        {
            if(ans.empty())
                ans.push(i.first);
            else
            {
                float a = (float)(target - ans.top())/buff[ans.top()];
                float b = (float)(target - i.first) / i.second;
                if(a < b)
                    ans.push(i.first);

            }
        }
        return ans.size();
    }
};