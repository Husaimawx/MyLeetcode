#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int t, m;
int* times;
int *value;
long long * dp;
long long getAns() {
    for (int i = 1; i <= m; i ++) {
        int temp_time = times[i-1];
        int temp_v = value[i-1];
        for (int j = 1; j <= t; j++) {
            if (j >= temp_time)
                dp[j] = max(dp[j], dp[j - temp_time] + temp_v);
        }
    }
    // for (int i = 0; i <= m; i++) {
        // for (int j = 0; j <= t; j++) {
            // cout << dp[i][j] << " ";
        // }
        // cout <<endl;
    // }
    return dp[t];
}

int main () {
    scanf("%d %d", &t, &m);
    times = new int[m];
    value = new int [m];
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &times[i], &value[i]);
    }
    dp = new long long [t + 1];
    memset(dp, 0, sizeof(long long) * (t+1));

    cout << getAns() << endl;
    return 0;
}