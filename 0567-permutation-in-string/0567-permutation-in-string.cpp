class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> list(26,0);
        vector<int> win(26,0);
        int i = s1.length();
        if(s2.length() < s1.length())
            return false;
        for(int x = 0;x<s1.length();x++)
        {
            list[s1[x] - 'a']++;
            win[s2[x] - 'a']++;
        }
        if(win == list) return true;
        for(int j = i;j<s2.length();j++)
        {
            win[s2[j] - 'a']++;
            win[s2[j - i] - 'a']--;
            if(win == list)
                return true;
        }
        return false;
    }
};