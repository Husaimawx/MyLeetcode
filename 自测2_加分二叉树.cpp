#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

long long dp[31][31];
int root[31][31];
int n;

void printRoot(int l, int r) {
    if (l > r) return;
    cout << root[l][r] << " ";
    if (l == r) return;
    printRoot(l, root[l][r] - 1);
    printRoot(root[l][r] + 1, r);
}

int main () {
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> dp[i][i];
        root[i][i] = i;
    }

    for (int i = n; i >= 1; i--) {
        for (int j = i + 1; j <=n; j ++) {
            dp[i][j] = dp[i + 1][j] + dp[i][i];
            root[i][j] = i;
            for (int mid = i+1; mid < j; mid ++) {
                if (dp[i][j] < dp[i][mid-1]*dp[mid+1][j] + dp[mid][mid]) {
                    dp[i][j] = dp[i][mid-1]*dp[mid+1][j] + dp[mid][mid];
                    root[i][j] = mid;
                }
            }
        }
    }

    cout << dp[1][n] << endl;
    printRoot(1, n);
    cout << endl;
    return 0;
}