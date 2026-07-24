class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_buy = prices[0];
        int max_profit = 0;

        for ( const int &price : prices ) {
            max_profit = max(max_profit, price - min_buy);
            min_buy = min(min_buy, price);
        }

        return max_profit;
    }
};
