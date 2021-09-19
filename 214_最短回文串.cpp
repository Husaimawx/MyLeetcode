#include <iostream>
#include <string>
using namespace std;

// 这里用dp判断了sij是不是回文串，复杂度n^2，超时
// 应该用KMP
class Solution {
public:
    bool ** dp;
    string shortestPalindrome(string s) {
        int n = s.size();
        dp = new bool*[n];
        for (int i = 0; i < n; i++) {
            dp[i] = new bool[n];
            memset(dp[i], 0, sizeof(bool) * n);
            
        }
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
            if (i + 1 < n) dp[i+1][i] = true;
        }

        for (int i = n-1; i >= 0; i--) {
            for (int j = i+1; j < n; j++) {
                if (s[i] == s[j] && dp[i+1][j-1]) {
                    dp[i][j] = true;
                }
            }
        }
        int maxl;
        for (int i = n - 1; i >= 0; i--) {
            if (dp[0][i]) {
                maxl = i + 1;
                break;
            }
        }
        // 这里可以用substr + reverse
        string ans = s;
        for (int i = maxl; i < n; i++) {
            ans = s[i] + ans;
        }
        
        return ans;
    }
};