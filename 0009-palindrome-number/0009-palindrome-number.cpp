class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        string n;
        int s;
        n = to_string(x);
        s = n.size();
        string r(s,' ');    
        for(int i = 0;i<n.size();i++)
        {
            r.at(i) = n[s-1];
            s--;
        }
        if(n.compare(r) == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};