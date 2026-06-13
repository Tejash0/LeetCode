class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int cl = nums[0]+ nums[1]+ nums[2];
        int j,k;
        int s = nums.size() - 1;

        for(int i = 0; i <= s; i++)
        {
            j = i+1;
            k = s;

            while(j < k)
            {
                
                 int sum = nums[i]+ nums[j]+ nums[k];
                if (abs(sum - target) < abs(cl - target)) {
                    cl = sum;
                }

                if (sum < target) {
                    ++j;
                } else if (sum > target) {
                    --k;
                } else {
                    return target; // Exact match found
                }
            }

        }
        return cl;
    
    }
};