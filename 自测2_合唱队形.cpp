#include <iostream>
#include <algorithm>
using namespace std;

int high[105];
int dp1[105];
int dp2[105];

int main () {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> high[i];
    }

    if (n == 2) {
        cout << 0 << endl;
        return 0;
    }
    dp1[0] = 1;
    for (int i = 1; i <= n; i++) {
        dp1[i] = 1;
        for (int j = 1; j < i; j++) {
            if (high[i-1] > high[j-1]) {
                dp1[i] = max(dp1[i], dp1[j] + 1);
            }
        }
    }

    dp2[n+1] = 1;
    for (int i = n; i >= 1; i--) {
        dp2[i] = 1;
        for (int j = i + 1; j <= n; j++){
            if (high[i-1] > high[j-1]) {
                dp2[i] = max(dp2[i], dp2[j] + 1);
            }
        }
    }

    int max_l = 0;
    for (int mid = 1; mid <= n; mid ++) {
        max_l = max(max_l, dp1[mid] + dp2[mid] - 1);
    }
    cout << n - max_l << endl;
    // for (int i = 1; i <= n; i++) {
    //     cout << dp1[i] << " ";
    // }
    // cout << endl;

    // for (int i = 1; i <= n; i++) {
    //     cout << dp2[i] << " ";
    // }
    // cout << endl;

    return 0;
}