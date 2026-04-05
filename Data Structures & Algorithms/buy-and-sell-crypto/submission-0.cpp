class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfitMade = 0;
        int start = 0, end = 0;
        int currentProfit = 0;
        for (int i = 0; i < prices.size(); i++) {
            start = end = i;
            currentProfit = prices[i];
            for (int j = i + 1; j < prices.size(); j++) {
                if (prices[j] > currentProfit) {
                    currentProfit = prices[j];
                    end = j;
                }
            }
            maxProfitMade = max(maxProfitMade, prices[end] - prices[start]);
        }
        return maxProfitMade;
    }
};
