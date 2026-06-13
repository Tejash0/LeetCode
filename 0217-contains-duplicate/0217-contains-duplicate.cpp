class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, char> dupe;
            for(int i = 0; i < nums.size(); i++)
            {
                int a = nums[i];
                if(dupe[a] == 't')
                {
                    return true;
                }
                else
                {
                    dupe[a] = 't';
                }
            }
        return false;
    }
};