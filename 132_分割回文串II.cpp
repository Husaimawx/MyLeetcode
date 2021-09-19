#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;

// 想破了头皮，没想出来，看的题解
// 思路：用dp[i][j]表示是否为回文串，然后用DP[i]表示 s[1...i]需要的最小切割次数
// 首先标记所有DP为0的地方，然后对于剩下的地方，依次遍历当前串的前继，if(dp[j + 1][i]) DP[i] = min(DP[i], DP[j] + 1);
// 其实说白了就是化解成子问题：把最后一个回文串先分出来，在剩下的里面去最小。

class Solution {
public:
    int minCut(string s) {
        int l = s.length();
        if (l == 0)
        {
            return 0;
        }

        bool **dp;
        dp = new bool*[l+1];
        for (int i = 0; i < l + 1; i++)
        {
            dp[i] = new bool[l + 1];
            memset(dp[i], 1, sizeof(bool) * (l + 1));
        }
        
        for (int i = l; i > 0; i--)
        {
            for (int j = i + 1; j <= l; j++)
            {
                dp[i][j] = dp[i+1][j-1] && s[i-1] == s[j-1];
            }
        }
        

        int* DP = new int[l + 1];
        
        for (int i = 0; i < l + 1; i++)
        {
            DP[i] = 20001;
        }
        
        
        for (int i = 1; i < l + 1; i++)
        {
            if (dp[1][i])
            {
                DP[i] = 0;
            }
            else {
                for (int j = 1; j < i; j++)
                {
                    if (dp[j + 1][i])
                    {
                        DP[i] = min(DP[i], DP[j] + 1);
                    }
                    
                }
                
            }
            
        }
        

        // for (int i = 0; i < l+1; i++)
        // {
        //     for (int j = 0; j < l+1; j++)
        //     {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        for (int i = 0; i < l + 1; i++)
        {
            cout << DP[i] << " ";
        }
        cout << endl;
        
        

        return DP[l];
    }
};

int main() {
    string s;
    cin >> s;
    Solution S;
    cout << S.minCut(s) << endl;
    return 0;
}