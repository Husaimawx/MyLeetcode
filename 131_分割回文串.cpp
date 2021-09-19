#include <iostream>
#include <string.h>
#include <vector>
using namespace std;


// 这个题其实包括两个题目，一个是通过回溯法找子集，一个是判断子串是否为回文串。
// 回溯其实很简单，十行代码，一开始没想清楚写了好久。思路就是每次在剩下的串上截取，截取长度从1到剩下的串长遍历，然后递归截取后的串，回溯，简单的dfs。
// 判断子串是否为回文串就是经典的dp，dp[i][j] 表示 s[i...j]为回文串，转移方程： dp[i][j] = dp[i + 1][j - 1] && s[i - 1] == s[j - 1];
// 不过一开始脑子抽了非要ij都从0开始遍历，这样会出现dp[i+1][j-1]还没算好就开始算dp[i][j]的问题，改成了i从后向前算，通过了。

class Solution {
public:
    vector<vector<string> > ans;
    vector<vector<string> > partition(string s) {
        int l = s.length();
        if (l == 0)
        {
            return ans;
        }
        bool** dp;
        dp = new bool*[l + 1];
        for (int i = 0; i < l + 1; i++)
        {
            dp[i] = new bool[l + 1];
            memset(dp[i], 1, sizeof(bool) * (l + 1));
        }
        
        for (int i = l - 1; i > 0; i--)
        {
            for (int j = i + 1; j < l + 1; j++)
            {
                dp[i][j] = dp[i + 1][j - 1] && s[i - 1] == s[j - 1];
            }
        }
        
        // for (int i = 0; i < l + 1; i++)
        // {
        //     for (int j = 0; j < l + 1; j++)
        //     {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        
        
        vector<string> cur;
        digui(s, cur, 0, dp);
        return ans;
    }
    void digui(string s, vector<string> cur, int pos, bool ** dp) {
        if (pos == s.length())
        {
            ans.push_back(cur);
            return;
        }
        
        for (int i = 1; i < s.length() - pos + 1; i++)
        {
            if (dp[pos + 1][pos+i])
            {
                string temp = s.substr(pos, i);
                cur.push_back(temp);
                digui(s, cur, pos + i, dp);
                cur.pop_back();    
            }
            
        }
    }
};

int main () {
    string s;
    cin >> s;
    Solution S;
    
    vector<vector<string> > ans = S.partition(s);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}