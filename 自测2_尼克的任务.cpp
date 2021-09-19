#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;

int n, k;
int * dp;
struct job {
    int p;
    int t;
    bool operator < (const job& j) const {
        return this->p > j.p;
    }
}jobs[10005];

int* has_job;

int main () {
    scanf("%d %d", &n, &k);
    has_job = new int[n + 1];
    memset(has_job, 0, sizeof(int)* (n+1));
    
    for (int i = 1; i <= k; i++) {
        scanf("%d %d", &jobs[i].p, &jobs[i].t);
        has_job[jobs[i].p] ++;
    }

    sort(jobs+1, jobs+k+1);
    
    // dp[i]: i~n的最大空闲时间
    // 当前没有工作：dp[i] = dp[i+1] + 1;
    // 当前有工作：dp[i] = max(dp[i], dp[i + a[sum]])
    
    int num = 1;
    dp = new int[n+1];
    for (int i = n; i >= 1; i--){
        if (has_job[i] == 0) {
            dp[i] = dp[i+1] + 1;
        }
        else {
            cout << i << " " << has_job[i] << endl;
            for (int j = 1; j <= has_job[i]; j++) {
                if (dp[i + jobs[num].t] > dp[i]) {
                    // cout << j << " " << num << endl;
                    dp[i] = dp[i + jobs[num].t];
                } 
                num++;
            }
        }
    }
    
    cout << dp[1] << endl;
    return 0;
}