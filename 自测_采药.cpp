#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int t, m;
int* times;
int *value;
int * dp;
int getAns() {
    for (int i = 1; i <= m; i ++) {
        for (int j = t; j >= times[i-1]; j--) {
            dp[j] = max(dp[j], dp[j - times[i-1]] + value[i-1]);
        }
    }
    return dp[t];
}

int main () {
    scanf("%d %d", &t, &m);
    times = new int[m];
    value = new int [m];
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &times[i], &value[i]);
    }
    dp = new int[t+1];
    memset(dp, 0, sizeof(int) * (t+1));

    cout << getAns() << endl;
    return 0;
}