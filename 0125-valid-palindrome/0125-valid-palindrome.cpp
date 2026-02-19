class Solution {
public:
    bool isPalindrome(string s) {
        int ss = s.length();
        int i = 0, j = ss-1;
        while(i<ss && j>=0)
        {
            char x = s[i];
            char y = s[j];
            if(iswalnum(x) && iswalnum(y))
            {
                if(!isdigit(x) || !isdigit(y))
                {
                    x = tolower(x);
                    y = tolower(y);
                }
                if(x != y)
                {
                    return false;
                }
                i++;
                j--;
            }
            else if(!iswalnum(x))
            {
                i++;
            }
            else if(!iswalnum(y))
            {
                j--;
            }
        }
        return true;
    }
};