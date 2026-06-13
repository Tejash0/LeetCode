class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(find(nums.begin(), nums.end(), target) == nums.end())
        {
            return -1;
        }
        auto is = find(nums.begin(), nums.end(), target);
        return distance(nums.begin(),is);
    }
};