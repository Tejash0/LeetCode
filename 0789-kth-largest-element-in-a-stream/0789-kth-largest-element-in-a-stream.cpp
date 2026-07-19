    class KthLargest {
    public:
        priority_queue<int,vector<int>, greater<int>> min_heap;
        int x;
        KthLargest(int k, vector<int>& nums) {
            x = k;
            for(int i : nums)
            {
                min_heap.push(i);
                if(min_heap.size() > k)
                min_heap.pop();
            }
        }
        int add(int val) {
            min_heap.push(val);
            if(min_heap.size()>x)min_heap.pop();
            return min_heap.top();
        }
    };
