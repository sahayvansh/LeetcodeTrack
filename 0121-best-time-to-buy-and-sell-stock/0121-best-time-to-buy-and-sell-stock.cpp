class Solution
{
    public:
        int maxProfit(vector<int> &prices)
        {
            int buyAt = INT_MAX;
            int maxi = 0;
            for (int i = 0; i < prices.size(); i++)
            {
                maxi = max(maxi, prices[i] - buyAt);
                buyAt = min(buyAt, prices[i]);
            }
            return maxi;
        }
};