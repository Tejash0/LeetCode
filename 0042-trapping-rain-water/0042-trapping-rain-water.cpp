class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> pre(n,0);
        vector<int> post(n,0);
        int maxi = 0;
        for(int i = 0;i<n;i++)
        {   
                pre[i] = maxi;
                maxi = max(height[i],maxi);
        }
        maxi = 0;
        for(int j = n-1; j>=0;j--)
        {
                post[j] = maxi;
                maxi = max(height[j],maxi);
        }
        maxi=0;
        for(int i = 1;i<n;i++)
        {
            if(pre[i]>height[i] && post[i] > height[i])
            {
                maxi += min(pre[i],post[i])-height[i];
            }
        }
        return maxi;
    }
};