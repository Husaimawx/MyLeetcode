#include <vector>
#include <iostream>
using namespace std;

// k种颜色，还是dp[i][j]

class Solution {
public:
    int minCostII(vector<vector<int> >& costs) {
        int n = costs.size();
        int k = costs[0].size();
        vector<vector<int> > dp(n+1, vector<int>(k+1, 0));
        for(int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                dp[i][j] = INT_MAX;
                for (int m = 1; m <= k; m++) {
                    if (m != j) {
                        dp[i][j] = min(dp[i][j], dp[i-1][m]);
                    }
                }
                dp[i][j] += costs[i-1][j-1];
            }
        }
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= k; j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        int ans = INT_MAX;
        for (int i = 1; i <= k; i++) {
            ans = min (ans, dp[n][i]);
        }
        return ans;
    }
};