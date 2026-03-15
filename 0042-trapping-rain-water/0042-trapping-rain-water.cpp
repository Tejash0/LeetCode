class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int pre[n],post[n];
        int maxi = 0;
        for(int i = 0;i<n;i++)
        {   
            if(height[i]>maxi)
            {
                pre[i] = maxi;
                maxi = height[i];
            }
            else
                pre[i] = maxi;
        }
        maxi = 0;
        for(int j = n-1; j>=0;j--)
        {
             if(height[j]>maxi)
            {
                post[j] = maxi;
                maxi = height[j];
            }
            else
                post[j] = maxi;
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