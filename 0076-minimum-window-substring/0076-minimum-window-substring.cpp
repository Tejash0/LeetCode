class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> p;
        for(char c:t)
            p[c]++;
        int count = 0;
        int i = 0,j = 0;
        int m = s.size()+1;
        int si = -1;
        while(j<s.size())
        {
            if(p[s[j]] > 0)count++;  
            p[s[j]]--;
            while(count == t.size())
            {
                if(m >j-i+1)
                {
                    m = j-i+1;
                    si=i;
                }
                p[s[i]]++;
                if(p[s[i]] > 0)count--;
                i++;
            }
            j++;
        }
        return si==-1 ? "" : s.substr(si, m);
    }
};
