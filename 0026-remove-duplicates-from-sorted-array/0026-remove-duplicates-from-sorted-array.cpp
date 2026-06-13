class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        vector <int> uniq;

        for(int i = 0;i < nums.size(); i++)
        {
            if(find(uniq.begin(),uniq.end(),nums[i]) == uniq.end())
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