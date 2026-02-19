class Solution {
public:
    bool isValid(string s) {
        string start = {"({["};
        string finish = {")}]"};
        stack <char> st;
        for(auto i:s)
        {
            if(start.find(i) != string::npos)
            {
                st.push(i);
            }
            else if(finish.find(i) != string::npos)
            {
                if(st.empty())return false;
                auto f = finish.find(i);
                if(st.top() == start[f])
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        if(!st.empty())return false;
        return true;

    }
};