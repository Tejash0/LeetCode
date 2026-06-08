class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int maxi = 0;
    int mini = prices[0];
    for(int i = 0; i <prices.size();i++)
    {
        if(prices[i]<mini)
        mini = prices[i];

        if(prices[i] - mini > maxi)
            maxi = prices[i]-mini;
    }
    return maxi;
    }
};