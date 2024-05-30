class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        int min_seen = INT_MAX, max_profit = 0; // If no chance of profit, do not buy/sell
        for (int i = 1; i < n; i++) {
            min_seen = min(min_seen, prices[i-1]);
            max_profit = max(max_profit, prices[i] - min_seen);
        }
        
        return max_profit;
    }
};