class Solution {
public:
    int dist(const vector<int>& p) {
        return p[0] * p[0] + p[1] * p[1];
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int left = 0, right = points.size() - 1;
        while (left <= right) {
            int pivotIndex = partition(points, left, right);
            if (pivotIndex == k) break;
            if (pivotIndex < k) left = pivotIndex + 1;
            else right = pivotIndex - 1;
        }
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }

private:
    int partition(vector<vector<int>>& points, int left, int right) {
        int pivot = dist(points[right]);
        int i = left;
        for (int j = left; j < right; ++j) {
            if (dist(points[j]) < pivot) {
                swap(points[i++], points[j]);
            }
        }
        swap(points[i], points[right]);
        return i;
    }
};