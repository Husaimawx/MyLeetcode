#include <vector>
#include <string>
using namespace std;

// 当前位匹配
//      dp[i][j] = dp[i-1][j-1];
// 当前位不匹配
//      前一位是*
//          dp[i][j] = dp[i-1][j] || dp[i][j-1];

class Solution {
public:
    bool isMatch(string s, string p) {

        int m = s.size();
        int n = p.size();
        if (m == 0 && n == 0) return s == p;

        vector<vector<bool> > dp (m + 1, vector<bool> (n + 1, false));
        dp[0][0] = true;
        
        for (int i = 1; i <= n; i++) {
            dp[0][i] = dp[0][i-1] && p[i-1] == '*';
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i-1] == p[j-1] || p[j-1] == '?') {
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    if (p[j-1] == '*') {
                        dp[i][j] = dp[i-1][j] || dp[i][j-1];
                    }
                }
            }
        }
        return dp[m][n];
    }
};