#include <iostream>
#include <string.h>
using namespace std;

// 有了之前的经验，一看题目就想到了动态规划
// 没看题解，想了大概一个小时，思路是dp[i][j]表示用s1的前i个字符和s2的前j个字符能否交替构造出s3的前i+j个字符。
// 但是转移方程一直写不出来，浪费了很长时间，最后写出了：dp[i][j] = (dp[i][j-1] && s2[j - 1] == s3[i + j - 1]) || (dp[i-1][j] && s1[i - 1] == s3[i + j - 1]);
// 就是说 dp[i][j] 要么从dp[i][j-1]得到，要么从dp[i-1][j]得到，并且还需要考虑字符串的相应位置是否相等。


class Solution {
public:
    bool ** dp;
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length();
        int n = s2.length();
        if (s3.length() != m + n)
        {
            return false;
        }
        
        dp = new bool*[m+1];
        for (int i = 0; i <= m; i++)
        {
            dp[i] = new bool[n+1];
            memset(dp[i], 0, sizeof(bool) * (n+1));
        }
        
        dp[0][0] = true;

        for (int i = 1; i <= m; i++)
        {
            dp[i][0] = dp[i - 1][0] && s1[i -1] == s3[i-1];
            if (!dp[i][0])
            {
                break;
            }
            
        }
        for (int i = 1; i <= n; i++)
        {
            dp[0][i] = dp[0][i - 1] && s2[i-1] == s3[i-1];
            if (!dp[0][i])
            {
                break;
            }
        }

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = (dp[i][j-1] && s2[j - 1] == s3[i + j - 1]) || (dp[i-1][j] && s1[i - 1] == s3[i + j - 1]);
            }
        }
        
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[m][n];
    }
};

int main() {
    string s1,s2,s3;
    // cin >> s1 >> s2 >> s3;
    s1 = "ab";
    s2 = "bc";
    s3 = "bbac";
    Solution S;
    cout << S.isInterleave(s1, s2, s3) << endl;

    return 0;
}