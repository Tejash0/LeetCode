class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int maxi = 0;
        for(int i = 0;i<n;i++)
        {
            if(!st.empty() && heights[st.top()] > heights[i])
            {
                while(!st.empty() && heights[st.top()] >  heights[i] )
                {
                    int x = st.top();
                    st.pop();
                    int l = st.empty() ? -1 : st.top();
                    maxi = max(maxi,(int)(heights[x] * (i - l - 1)));
                }
            }
            st.push(i);
        }
        while(!st.empty())
        {
            int x = st.top();
            st.pop();
            int l = st.empty() ? -1 : st.top();
            maxi = max(maxi,(int)(heights[x] * (n - l - 1)));
        }
        return maxi;
    }
};
