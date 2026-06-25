class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0,r = matrix.size()-1;
        while(l<=r)
        {
            int m = (r+l)/2;
            int n = matrix[m].size() - 1;
            if(matrix[m][0] <= target && matrix[m][n] >= target)
            {
                if(matrix[m][0] == target || matrix[m][n] == target)
                    return true;
                int left = 0;
                int right = n;
                while(left<=right)
                {
                    int mid = (right+left)/2;
                    if(matrix[m][mid] == target)return true;
                    else if(matrix[m][mid] > target)right = mid - 1;
                    else left = mid+1;
                }
                return false;
            }
            else if(matrix[m][0] > target)r = m-1;
            else l = m+1;
        }
        return false;
    }
};
