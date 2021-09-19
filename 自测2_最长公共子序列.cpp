#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;

int n;
int a[100005];
int b[100005];
int* dp;

// O(n^2) dp 压缩空间 超时

int main () {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    
    dp = new int [n+1];
    memset(dp, 0, sizeof(n+1));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i-1] == b[j-1])
                dp[j] = dp[j-1] + 1;
            else 
                dp[j] = max(dp[j], dp[j-1]);
        }
    }
    printf("%d\n", dp[n]);
    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= n; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}