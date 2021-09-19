#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

const int maxn = 1005;
bool dp[maxn][maxn];

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
            if (i > 0) dp[i][i-1] = true; 
        }
        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                dp[i][j] = dp[i+1][j-1] && s[i] == s[j];
                ans += dp[i][j];
            }
        }
        return ans + n;
    }
};

int main () {
    string s;
    cin >> s;
    Solution S;
    cout << S.countSubstrings(s);
    return 0;
}