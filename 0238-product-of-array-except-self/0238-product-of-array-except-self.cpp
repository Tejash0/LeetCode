class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int s = nums.size();
        vector<int> ans(s,1);
        int pre = 1;
        int post = 1;
        ans[0]=1;
        for(int i = 0;i < s;i++)
        {
            ans[i] *= pre;
            pre *= nums[i];
        }
        for(int j = s-1; j >= 0; j--)
        {
            ans[j] *= post;
            post *= nums[j];
        }
        return ans;
    }
};