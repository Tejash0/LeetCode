class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
       int s = temperatures.size();
       vector<int> ans(s,0);
       stack<int> st;

       for(int i = 0; i < s;i++){
            while(!st.empty() && temperatures[i]>temperatures[st.top()])
            {
                int x = st.top();
                st.pop();
                ans[x] = i-x;
            }
            st.push(i);
       }
       return ans;
    }
};