#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int> > dp(n + 1, vector<int>(3, 0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[0][2] = INT_MIN;

        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][2]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
            dp[i][2] = dp[i-1][1] + prices[i];
        }
        return max(dp[n-1][0], dp[n-1][2]);
    }
};