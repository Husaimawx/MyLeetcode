#include <iostream>
#include <algorithm>
using namespace std;

struct stick{
    int l;
    int w;
    bool operator < (const stick& s) const {
        return this->l == s.l ? this->w > s.w : this->l > s.l;
    }
}sticks[5005];
int dp[5005];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> sticks[i].l >> sticks[i].w;
    }
    
    sort(sticks, sticks + n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (sticks[i].w > sticks[j].w) {
                dp[i] = max (dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans+1 << endl;
    return 0;
}