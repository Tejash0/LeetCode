class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int n =  nums.size()-1;
        int r = n;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[l]<=nums[mid])
            {
                if(nums[l]<=target && nums[mid]>target)
                {
                    r = mid-1;
                }
                else
                {
                    l = mid+1;
                }
            }
            else
            {
                if(nums[r]>=target && nums[mid]<target)
                {
                    l = mid+1;
                }
                else
                {
                    r = mid-1;
                }
            }
        }
        return -1;
    }
};