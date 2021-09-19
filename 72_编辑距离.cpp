#include <iostream>
#include <string.h>
using namespace std;

class Solution {
public:
    int** dp;
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        if (m==0||n==0)
        {
            return m+n;
        }
        
        dp = new int* [m+1];
        for (int i = 0; i < m+1; i++)
        {
            dp[i] = new int [n+1];
            memset(dp[i], 0, sizeof(int)* (n+1));
        }

        dp[0][0] = 0;

        for (int i = 0; i < m+1; i++)
        {
            dp[i][0] = i;
        }

        for (int i = 0; i < n+1; i++)
        {
            dp[0][i] = i;
        }

        
        for (int i = 1; i < m+1; i++)
        {
            for (int j = 1; j < n+1; j++)
            {
                int temp = min(dp[i][j-1] + 1, dp[i-1][j] + 1);
                if (word1[i-1] == word2[j-1])
                {
                    dp[i][j] = min(temp, dp[i-1][j-1]);
                }
                else {
                    dp[i][j] = min(temp, dp[i-1][j-1] + 1);
                }
                
            }
        }
        for (int i = 0; i < m+1; i++) {
            for (int j = 0; j < n+1; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        
        return dp[m][n];
    }
};

// 插入一个字符
// 删除一个字符
// 替换一个字符

// 输入：word1 = "horse", word2 = "ros"
// 输出：3

int main() {
    string word1, word2;
    cin >> word1 >> word2;
    Solution S;
    cout << S.minDistance(word1, word2) << endl;

    return 0;
}