class Solution {
public:
    int maxProfit(vector<int>& x) {
        int n = x.size();
        int mini = x[0];
        int profit = 0;
        for(int i = 1;i<n;i++){
            int cost = x[i] - mini;
            profit = max(profit,cost);
            mini = min(mini,x[i]);
        }
        return profit;
    }
};