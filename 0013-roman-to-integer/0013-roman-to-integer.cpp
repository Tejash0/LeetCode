class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> orig = {{'I',1},
                                        {'V',5},
                                        {'X',10},
                                        {'L',50},
                                        {'C',100},
                                        {'D',500},
                                        {'M',1000}};
        int num=0;
        for(int i =0; i<s.length();i++)
        {   
            int x = orig[s[i]];
            if(x < orig[s[i+1]])
            {
                num+=orig[s[i+1]]-x;
                i++;
            }
            else
            {
                num = num + x;
                cout<<num<<" ";
            }
        }
        return num;
    }
};