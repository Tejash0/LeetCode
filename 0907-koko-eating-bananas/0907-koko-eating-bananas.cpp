class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int m = 0;
        for(int x : piles)m = max(m,x);
        int l = 1;
        while(l<=m)
        {
            int mid = (l+m)/2;
            long x = 0;
            for(int i = 0;i < piles.size();i++)x += ceil((double)piles[i]/(double)mid);
            if(x<=h)m = mid-1;
            else l = mid+1;
        }
        return l;
    }
};
