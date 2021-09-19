#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M;
const int maxn = 100005;
int dp[maxn];

int main () {
    scanf("%d %d", &N, &M);
    for (int i = N; i <= M; i++) {
        dp[i] = M + 1;
    }
    dp[N] = 0;
    for (int i = N; i <= M; i++) {
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                int k = i / j;
                if (i + j <= M) dp[i + j] = min (dp[i + j], dp[i] + 1);
                if (i + k <= M) dp[i + k] = min (dp[i + k], dp[i] + 1);
            }
        }
    }
    if (dp[M] == M + 1) printf("-1");
    else printf("%d", dp[M]);
    return 0;
}