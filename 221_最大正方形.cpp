#include <iostream>
#include <vector>
using namespace std;


// dp[i][j] 是 00 到 ij 的全为1的最大正方形边长
// dp[i][j] = min(dp[i-1][j-1], dp[i][j-1], dp[i-1][j]) + 1

class Solution {
public:
    int maximalSquare(vector<vector<char> >& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        vector<vector<int> > dp(m+1, vector<int>(n+1, 0));
        for (int i = 1; i <= m; i ++) {
            for (int j = 1; j <= n; j ++) {
                if (matrix[i-1][j-1] == '1') {
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans*ans;
    }
};