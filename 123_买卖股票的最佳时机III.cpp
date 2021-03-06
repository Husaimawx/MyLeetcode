#include <vector>
#include <iostream>
using namespace std;


#define MMIN -12345689
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int> > > dp (n, vector<vector<int> >(2, vector<int>(3, 0)));
        dp[0][0][0] = 0;
        dp[0][1][1] = MMIN;
        dp[0][1][2] = -prices[0];

        for (int i = 1; i < n; i++) {
            dp[i][0][0] = max(dp[i-1][0][0], dp[i-1][1][1] + prices[i]);
            dp[i][0][1] = max(dp[i-1][0][1], dp[i-1][1][2] + prices[i]);
            dp[i][0][2] = dp[i-1][0][2];

            dp[i][1][0] = dp[i-1][1][0];
            dp[i][1][1] = max(dp[i-1][1][1], dp[i-1][0][1] - prices[i]);
            dp[i][1][2] = max(dp[i-1][1][2], - prices[i]);
        }
        return max(dp[n-1][0][0], max(dp[n-1][0][1], dp[n-1][0][2]));
    }
};