#include <iostream>
#include <vector>
using namespace std;

// dp[i][j] 前i枚硬币有j枚朝上的概率
// 两种情况，这枚朝上、这枚朝下
// dp[i][j] = min(1.0, dp[i-1][j] * (1.0 - p) + dp[i-1][j-1] * p);

class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        int n = prob.size();
        vector<vector<double> > dp(n+1, vector<double>(target+1, 0));
        
        dp[0][0] = 1;
        for (int i = 1; i <= target; i++) {
            dp[0][i] = 0;
        }

        for (int i = 1; i <= n; i++) {
            dp[i][0] = dp[i-1][0] * (1.0-prob[i-1]);
        }
        for (int i = 1; i <= n; i++) {
            double p = prob[i-1];
            for (int j = 1; j <= target; j++) {
                dp[i][j] = min(1.0, dp[i-1][j]*(1.0 - p) + dp[i-1][j-1] * p);
            }
        }
        return dp[n][target];
    }
};