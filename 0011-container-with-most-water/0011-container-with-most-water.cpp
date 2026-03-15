class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0,right = n-1;
        int maxi = 0;
        while(left<right)
        {
            if(height[left] >= height[right])
            {
                int a = height[right] * (right-left);
                maxi = max(maxi,a);
                right--;
            }
            else if(height[left] < height[right])
            {
                int a = height[left] * (right-left);
                maxi = max(maxi,a);
                left++;  
            }
        }
        return maxi;
    }
};