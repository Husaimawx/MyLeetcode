#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    // 用 dp[x] 表示金额之和等于 x 的硬币组合数，目标是求 dp[amount]
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        //
        for (int j = 1; j <= n; j++) {
            for (int i = coins[j-1]; i <= amount; i++) {
                dp[i] += dp[i - coins[j-1]];
            }
        }
        // for (int i = 1; i <= amount; i++) {
        //     cout << dp[i] << " ";
        // }
        // cout << endl;
        return dp[amount];
    }
};