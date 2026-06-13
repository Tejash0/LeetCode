class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        vector <int> uniq;
        
        for(int i = 0;i < nums.size(); i++)
        {
            if(nums[i] != val)
            {
                uniq.push_back(nums[i]);
            }
        }
        for(int i = 0;i < uniq.size(); i++)
        {
            nums[i] = uniq[i];
        }
        return uniq.size();
    }
};