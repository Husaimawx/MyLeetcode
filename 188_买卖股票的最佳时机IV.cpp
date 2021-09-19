#include <iostream>
#include <vector>
using namespace std;

// 用两个dp数组sell[i], buy[i]，表示第i次卖出、买入时的最大收入
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n < 2) return 0;
        if (k >= n) {
            int max_profits = 0;
            for (int i = 1; i < n; i++) {
                if (prices[i] > prices[i-1]) {
                    max_profits += prices[i] - prices[i-1];
                }
            }
            return max_profits;
        }

        vector<vector<int> > dp(2, vector<int>(k+1, 0));
        for (int i = 0; i <= k; i++) {
            dp[0][i] = INT_MIN;
        }
        // vector<int> dp_buy(k + 1, INT_MIN);
        // vector<int> dp_sell(k + 1, 0);
        

        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                dp[0][j] = max(dp[0][j], dp[1][j-1] - prices[i]);
                dp[1][j] = max(dp[1][j], dp[0][j] + prices[i]);
            }
        }
        return dp[1][k];
    }
};