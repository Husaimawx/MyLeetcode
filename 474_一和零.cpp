#include <iostream>
#include <vector>
#include <string>
using namespace std;


// 二维背包 dp[i][j][k]，jk同时考虑
class Solution {
public:
    int getZero(string s) {
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') cnt++;
        }
        return cnt;
    }

    int getOne(string s) {
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') cnt++;
        }
        return cnt;
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        int l = strs.size();
        vector<vector<vector<int> > > dp(l+1, vector<vector<int> >(m+1, vector<int>(n+1, 0)));

        for (int i = 1; i <= l; i++) {
            string cur = strs[i - 1];
            int zc = getZero(cur);
            int oc = getOne(cur);
            // cout << "zc " << zc << " oc " << oc << endl;  
            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= n; k++) {
                    if (j >= zc && k >= oc ) {
                        dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j-zc][k-oc] + 1);
                    }
                    else {
                        dp[i][j][k] = dp[i-1][j][k];
                    }
                }
            }
        }
        // for (int i = 1; i <= l; i++) {
        //     for (int j = 1; j <= m; j++) {
        //         for (int k = 1; k <= n; k++) {
        //             cout << dp[i][j][k] << ""
        //         }
        //     }
        // }

        return dp[l][m][n];
    }
};