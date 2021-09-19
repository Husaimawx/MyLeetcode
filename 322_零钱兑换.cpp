#include <iostream>
#include <vector>
using namespace std;

// 硬币无限，完全背包
// dp[i][j]: 前i种硬币，组成金额j的最小硬币数
// dp[i][j] min (dp[i-1][j], dp[i][i-coins[j]] + 1)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1, amount+2);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < n; j++) {
                if (i >= coins[j]) {
                    dp[i] = min(dp[i], dp[i-coins[j]] + 1);
                }
            }
        }
        // for (int i = 0; i <= amount; i ++) {
        //     cout << dp[i] << " "; 
        // }
        // cout <<endl;
        if (dp[amount] == amount+2) {
            return -1;
        } 
        return dp[amount];
    }
};