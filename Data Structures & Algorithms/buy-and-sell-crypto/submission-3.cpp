class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int start = 0, end = 0;
        int bestBuy = prices[0];
        int maxProfit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > bestBuy) {
                maxProfit = max(maxProfit, prices[i] - bestBuy);
            }
            bestBuy = min(bestBuy, prices[i]);
        } 
        return maxProfit;
    }
};
