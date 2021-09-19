#include <iostream>
#include <utility>
using namespace std;

int n, m;
int a[101];
int dp[101];

// 01背包
// dp[i][j] : 前i种花总共放j个花的最大方案数
// dp[i][j] = dp[i-1][j] + dp[i-1][j-k], k为0～a[i]
// dp[0][0] 保证为1种

const int mod = 1000007;
int main () {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 0; j--) {
            for (int k = 1; k <= min(a[i-1], j); k++) {
                dp[j] = (dp[j] + dp[j-k]) % mod;
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}