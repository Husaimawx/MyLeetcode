#include <iostream>
#include <string.h>
#include <vector>
#include <map>
#include <stack>
using namespace std;

// DFS + 回溯
// 二进制转数字：翻转，第i位为1则加pow(2,i)

class Solution {
public:
    vector<int> grayCode(int n) {
        string s;
        
        for (int i = 0; i < n; i++)
        {
            s.push_back('0');
        }
        
        vector<int> ans;

        stack<string> q;
        map<string, bool> v;
        q.push(s);
        v[s] = true;
        while (!q.empty())
        {
            string p = q.top();
            q.pop();
            cout << p << endl;
            ans.push_back(getInt(p));
            for (int i = p.length(); i >= 0; i--)
            {
                if (p[i] == '0')
                {
                    p[i] = '1';
                }
                else {
                    p[i] = '0';
                }
                if (!v[p])
                {
                    q.push(p);
                    v[p] = true;
                    break;
                }
                if (p[i] == '0')
                {
                    p[i] = '1';
                }
                else {
                    p[i] = '0';
                }
            }
            
        }
        return ans;
    }
    int getInt(string s) {
        int ans = 0;
        reverse(s.begin(), s.end());
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '1')
            {
                ans += pow(2, i);
            }
            
        }
        return ans;
        
        
    }
};


int main () {
    int n;
    cin >> n;
    Solution S;
    vector<int> ans = S.grayCode(n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    // string s;
    // cin >> s;
    // cout << S.getInt(s) << endl;
    return 0;
}