class Solution {
public:
    int maxProfit(vector<int>& x) {
        int n = x.size();
        int buyprice = INT_MAX;
        int maxProfit = 0;

        for(int i = 0; i < n ; i++) {
            buyprice = min(buyprice, x[i]);
            int profit = x[i] - buyprice;
            maxProfit = max(maxProfit, profit);
        }

        return maxProfit;
    }
};