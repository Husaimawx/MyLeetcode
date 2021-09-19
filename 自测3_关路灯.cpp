
// f[i][j]记为当从i到j的灯都熄灭后剩下的灯的总功率，f[i][j][0]表示关掉i到j的灯后，老张站在左端点，f[i][j][1]表示关掉[i][j]的灯后,老张站在右端点
// f[i][j][0] = min ( f[i+1][j][0] + ( a[i+1] - a[i] ) * ( sum[i] + sum[n] - sum[j] ) , f[i+1][j][1] + ( a[j]-a[i] ) * ( sum[i]+sum[n]-sum[j]) );
// f[i][j][1] = min ( f[i][j-1][0] + ( a[j] - a[i] ) * ( sum[i-1] + sum[n] - sum[j-1] ) , f[i][j-1][1] + ( a[j]-a[j-1] ) * ( sum[i-1] + sum[n] - sum[j-1] ) );

#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 55;
int pos[MAXN], valt[MAXN], sum[MAXN], n, m, c;
int dp[MAXN][MAXN][2];

int main () {
    cin >> n >> c;
    memset(dp, INT_MAX, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        cin >> pos[i] >> valt[i];
        sum[i] = sum[i-1] + valt[i];
    }
    dp[c][c][0] = dp[c][c][1] = 0;
    for (int l = 2; l <= n; l++) {
        for (int i = 1; i + l - 1 <= n; i++) {
            int j = i + l - 1;
            dp[i][j][0] = min(dp[i+1][j][0] + (pos[i+1] - pos[i]) * (sum[i] + sum[n] - sum[j]),
                            dp[i+1][j][1] + (pos[j] - pos[i]) * (sum[i] + sum[n] - sum[j]));
            dp[i][j][1] = min(dp[i][j-1][0] + (pos[j] - pos[i]) * (sum[i-1] + sum[n] - sum[j-1]),//同上
                            dp[i][j-1][1] + (pos[j] - pos[j-1]) * (sum[i-1] + sum[n] - sum[j-1]));
        }
    }
    int ans = min(dp[1][n][0],dp[1][n][1]);
    printf("%d\n",ans);
    return 0;
}