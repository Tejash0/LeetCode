class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> freq;
        int l =0,r = 0,m = 0;
        int ans = 0;
        while(r<s.length())
        {
            freq[s[r]]++;
            m = max(m,freq[s[r]]);
            if(r-l+1 - m > k)
            {
                freq[s[l]]--;
                l++;
            }
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};