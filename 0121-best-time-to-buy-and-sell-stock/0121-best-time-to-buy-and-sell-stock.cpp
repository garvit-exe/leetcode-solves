class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int a = prices[0], b = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < a) a = prices[i];
            b = max(prices[i] - a, b);
        }

        return b;
    }
};