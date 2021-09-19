#include <iostream>
#include <climits>
using namespace std;

int N;
const int maxn = 55;
int num[maxn];
char op[maxn];
int tempnum[maxn];
char tempop[maxn];
long long dp[maxn][maxn];
// 4
// 1 + 2 * 4 + 5 *
long long maxS;
int ans;
void one (int s){
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dp[i][j] = LONG_MIN;
            if (i == j) {
                dp[i][i] = tempnum[i];
            }
        }
    }
    for (int i = N; i > 0; i--) {
        for (int j = i + 1; j <= N; j++) {
            for (int k = i; k < j; k ++) {
                if (tempop[k] == '+') {
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k+1][j]);
                }
                else if (tempop[k] == '*') {
                    dp[i][j] = max(dp[i][j], dp[i][k] * dp[k+1][j]);
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    cout << dp[1][N] << endl;
    if (dp[1][N] > maxS) {
        maxS = dp[1][N];
        ans = s;
    }
}
// 10
// -3 + 4 * -5 * 1 + -5 * 4 + -5 * -4 + -4 + 4 +

int main () {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> num[i] >> op[i];
    }

    maxS = INT_MIN;
    for (int bias = 1; bias <= N; bias++) {
        int s = bias;
        int i = s;
        int len = 0;
        while (len <= N) {
            tempnum[len] = num[i];
            tempop[len] = op[i];
            len++;
            i++;
            if (i > N) i = i % N;
        }
        // cout << "____________" << bias << " " << s << " " << i << " " << len << endl;
        // int startpos = s;
        // if (startpos == 0) startpos = N;
        // cout << startpos << endl;
        // cout <<"        " <<s << endl;
        one(s);
        // for (int i = 1; i <= N; i++) {
        //     cout << tempnum[i] << " ";
        // }
        // cout << endl;
        // for (int i = 1; i < N; i++) {
        //     cout << tempop[i] << " ";
        // }
        // cout << endl;
    }
    cout << ans << endl;
    

    return 0;
}