#include <iostream>
#include <vector>
using namespace std;
string s,p;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        vector<vector<int> > dp(m+1, vector<int>(n+1, false));

        dp[0][0] = true;
        for (int i = 1; i <= n; i ++) {
            if (p[i-1] == '*' && dp[0][i-2]) {
                dp[0][i] = true;
            }
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i-1] == p[j-1] || p[j-1] == '.') // 当前匹配
                    dp[i][j] = dp[i-1][j-1];
                else { // 当前不匹配
                    if (p[j-1] == '*') { // 前一个是*
                        if (s[i-1] != p[j-2] && p[j-2] != '.') { // 前两个不匹配
                            dp[i][j] = dp[i][j-2]; // 取0次
                        }
                        else {
                            dp[i][j] = dp[i-1][j] || dp[i][j-1] || dp[i][j-2]; //前两个匹配
                            // 取多次、1次、0次
                        }
                    }
                }
            }
        }
        // for (int i = 0; i <= m; i++) {
        //     for (int j = 0; j <= n; j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return dp[m][n];
    }
};