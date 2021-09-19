#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;
int s [100005];
int n;
int * dp;

// O(n^2) dp

void getAns() {
    memset(dp, 0, sizeof(int) * (n+1));
    // dp[i]: 以i开始的最长不上升子序列
    int max_ans = 0; 
    for (int i = n; i > 0; i--) {
        dp[i] = 1;//注意这里， 初识时应该有1个长度
        for (int j = i+1; j <= n; j++) {
            if (s[j] <= s[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        max_ans = max(max_ans, dp[i]);
    }

    // dp[i]: 以i结束的最长上升子序列
    memset(dp, 0, sizeof(int) * (n+1));
    int max_num = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;//注意这里， 初识时应该有1个长度
        for (int j = 1; j < i; j++) {
            if (s[i] > s[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        max_num = max(max_num, dp[i]);
    }
    printf("%d\n%d\n", max_ans, max_num);
}
// 389 207 155 300 299 170 158 65
int main () {
    n = 0;
    while(scanf("%d", &s[++n])!=EOF);
    n--;
    // n = 8;
    // for (int i = 0; i < n; i++) {
    //     scanf("%d", &s[i]);
    // }
    dp = new int[n+1];
    
    getAns();
    return 0;
}


