#include <vector>
#include <iostream>
using namespace std;

// 此消彼长

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();

        vector<vector<int> > dp(n+1, vector<int>(n+1, 0));

        for (int i = 0; i < n; i++) {
            dp[i][i] = piles[i];
        }

        for (int i = n-1; i >= 0; i--) {
            for (int j = i+1; j < n; j++) {
                dp[i][j] = max(piles[i] - dp[i+1][j], piles[j] - dp[i][j-1]);
            }
        }
        return dp[0][n-1];
    }
};