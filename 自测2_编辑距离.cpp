#include <iostream>
#include <string.h>
#include <string.h>
#include <algorithm>
using namespace std;

string a,b;
int ** dp;

int getAns() {
    int m = a.size();
    int n = b.size();

    dp = new int*[m+1];
    for (int i = 0; i < m+1; i++) {
        dp[i] = new int[n+1];
        memset(dp[i], 0, sizeof(int) * (n+1));
    }

    dp[0][0] = 0;

    for (int i = 1; i <= m; i++) {
        dp[i][0] = i;
    }
    for (int j = 1; j <= n; j++) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]), dp[i-1][j-1]) +1;
            }
        }
    }

    return dp[m][n];
}

int main () {
    cin >> a >> b;
    cout << getAns() << endl;

    return 0;
}