#include <iostream>
#include <vector>
using namespace std;

// dp[k][n]
// dp[i][j] = 遍历x x属于1到j min(dp[i][n-x], dp[i-1][x-1]); 
// 二分查找
class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int> > dp(k+1, vector<int>(n+1, 10005));

        for (int i = 0; i <= k; i++) {
            dp[i][0] = 0;
        }

        dp[0][1] = 0;
        for (int i = 0; i <= k; i++) {
            dp[i][1] = 1;
        }

        for (int j = 1; j <= n; j++) {
            dp[0][j] = 0;
            dp[1][j] = j;
        }

        for (int i = 2; i <= k; i++) {
            for (int j = 2; j <= n; j++) {
                int l = 1, h = j;
                while(l <= h) {
                    int mid = (l + h) / 2;
                    int ln = dp[i-1][mid-1];
                    int hn =  dp[i][j-mid];
                    if (ln < hn) {
                        l = mid + 1;
                    }
                    else {
                        h = mid - 1;
                    }

                }
                dp[i][j] = min(dp[i][j], dp[i-1][l-1] + 1);

            }
        }
        // for (int i = 0; i <= k ; i++) {
        //     for (int j = 0; j <= n; j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return dp[k][n];
    }
};