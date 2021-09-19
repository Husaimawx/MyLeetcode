#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// 使得m个子数组的和的 最大值 最小
// 枚举k，将前i个数分成j段
// min (dp[i][j], max(dp[k][j-1], sum(i, k)))

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<int> pre (n+1, 0);
        
        for (int i = 0; i < n; i++) {
            pre[i+1] = pre[i] + nums[i];
        }
        // dp[i][j] = 前i个数，分成j段
        // dp[i][j] = min(max(dp[k][j-1], sub(k + 1, i)))

        vector<vector<int> > dp(n + 1, vector<int>(m + 1, INT_MAX));
        dp[0][0] = 0;
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= min(i, m); j++) {
                for (int k = 0; k < i; k ++) {
                    dp[i][j] = min(dp[i][j], max(dp[k][j-1], pre[i] - pre[k]));
                }
            }
        }
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= m; j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return dp[n][m];
    }
};

int main () {
    vector<int> nums;
    int m;
    return 0;
}