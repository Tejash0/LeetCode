class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       unordered_map<char,int> unique;
       int j = 1;
       int maxi = 0;
        int i = 0;
        if(s.length() < 2)
            return s.length();
        unique[s[i]] = 1;
        while(j < s.length())
        {
            if(unique[s[j]] != 1)
            {    
                unique[s[j]] = 1;
                j++;
                maxi = max(maxi,(int)unique.size());
            }
            else
            {
                unique.erase(s[i]);
                i++;
            }

        }
    return maxi;
    }
};