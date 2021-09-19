#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 250;
int n, ans = 0, dp[N][N];
// dp[i][j]表示区间 i-j 合并的最大值
// 若dp[i][k] == dp[k+1][j] 则 dp[i][j] = max(dp[i][k]+1,dp[i][j])
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d",&dp[i][i]);
        ans = max(ans, dp[i][i]);
    }
    for (int i = n-1; i >= 1; i--)
        for (int j = i+1; j <= n; j++){
            for (int k = i; k < j; k++)
                if (dp[i][k] == dp[k+1][j])
                    dp[i][j] = max(dp[i][j],dp[i][k]+1);
            ans = max(ans, dp[i][j]);
        }
    printf("%d",ans);
    return 0;
}