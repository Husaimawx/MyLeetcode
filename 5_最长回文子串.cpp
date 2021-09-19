#include <iostream>
#include <string>

using namespace std;

// 思路：动态规划
// 回文串去掉首尾后还是回文串
// P(i,j) : 字符串s从i到j是否为回文串
// P(i,j) = P(i+1, j-1) && s[i] == s[j]
// 考虑边界条件：
// P(i,i) = 1
// P(i,i+1) = s[i] == s[i+1]
// 在状态转移方程中，我们是从长度较短的字符串向长度较长的字符串进行转移的
// 因此一定要注意动态规划的循环顺序。

string getLongestPalindrome(string s){
    int n = s.length();
    int** dp = new int* [n];
    for (int i = 0; i < n; i++)
    {
        dp[i] = new int [n];
        memset(dp[i], 0, n * sizeof(int));
    }
    
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i+k < n; i++)
        {
            int j = i + k;
            if (k == 0)
            {
                dp[i][j] = 1;
            }
            else if (k == 1)
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = 1;
                }
            }
            else {
                if (dp[i+1][j-1] == 1 && s[i] == s[j])
                {
                    dp[i][j] = 1;
                }
            }
        }
    }
    int longest_dis = -1;
    int longest_i = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (dp[i][j] == 1 && j - i >= longest_dis)
            {
                longest_dis = j - i + 1;
                longest_i = i;
            }
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        delete[] dp[i];
    }
    delete[] dp;
    string ans = s.substr(longest_i, longest_dis);
    return ans;
}

int main(){
    string a;
    cin >> a;
    cout << getLongestPalindrome(a) << endl;
    return 0;
}