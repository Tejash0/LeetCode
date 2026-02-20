class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> check = {'.'};
        for(int i = 0;i<board.size();i++)
        {
            check.clear();
            for(int j = 0;j<board[i].size();j++)
            {
                char x = board[i][j];
                if(x != '.')
                {   
                    if(check.find(x) != check.end())
                    {
                        return false;
                    }
                    check.insert(x);
                }
            }
        }
        for(int i = 0;i<board.size();i++)
        {
            check.clear();
            for(int j = 0;j<board[i].size();j++)
            {
                char x = board[j][i];
                if(x != '.')
                {   
                    if(check.find(x) != check.end())
                    {
                        return false;
                    }
                    check.insert(x);
                }
            }
        }
        int m=3,n=0,j;
        int count = 0;
        check.clear();
        for(int i = 0;i<10;i++)
        {
            if(i == 9)
            {
                n = m;
                m+=3;
                if(n>=9) break;
                i = -1;
                continue;

            }
            if(count == 9)
            {
                check.clear();
                count = 0;
            }
            for(j = n;j<m;j++)
            {
                char x = board[i][j];
                if(x != '.')
                {   
                    if(check.find(x) != check.end())
                    {
                        return false;
                    }
                    check.insert(x);
                }
            }    
            count+=3;   
        }
        return true;
    }
};