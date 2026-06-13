class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> check;

            for(int i = 0; i < nums.size(); ++i)
            {
                int a = nums[i];
                if(check.find(target-a) != check.end() )
                {
                    ans.push_back(check[target-a]);
                    ans.push_back(i);
                }
                else
                {
                    check[a] = i;
                }
            }  
        return ans; 
    }
};
