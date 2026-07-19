class Solution {
public:
    int value(vector<int> & a)
    {
        return a[0]*a[0] + a[1] * a[1];
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int i = 0,j = 0;
        int l = 0,r = points.size()-1;
        while(l<=r)
        {
            int ran = l + rand() % (r - l + 1);
            swap(points[ran],points[r]);
            int p = r;
            
            while(j<=p)
            {
                if(j == p)
            {
                swap(points[i],points[p]);
                if(k == i)return vector<vector<int>>(points.begin(),points.begin()+k);
                else if(k < i)
                {
                    r = i-1;
                    i = l;
                    j = l;
                }
                else
                {
                    i = i+1;
                    l = i;
                    j = i;
                }
                break;  
            }
            else if(value(points[j]) < value(points[p]))
            {
                swap(points[i],points[j]);
                i++;
                j++;
            }
            else
            {
                j++;
            }
            }
        }

        return vector<vector<int>>(points.begin(),points.begin()+k);
    }
};
