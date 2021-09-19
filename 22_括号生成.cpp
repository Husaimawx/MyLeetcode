#include <iostream>
#include <string.h>
#include <vector>
using namespace std;


// 输入：n = 3
// 输出：["((()))","(()())","(())()","()(())","()()()"]
// 3 0 0 
// ( 
// 3 1 0
// ((  ()
// 3 2 0
// 3 1 1


class Solution {
    vector<string> ans;
public:
    vector<string> generateParenthesis(int n) {
        string row;
        digui(n, 0, 0, row);
        return ans;
    }
    // 两个计数器，记录当前左右括号数量
    void digui(int n, int pre, int back, string row) {
        if (pre == n && back == n)
        {
            ans.push_back(row);
            return;
        }
        else if (pre == n)
        {
            digui(n, pre, back + 1, row + ')');
        }
        else if (pre == back)
        {
            digui(n, pre + 1, back, row + '(');
        }
        else if (pre > back)
        {
            digui(n, pre + 1, back, row + '(');
            digui(n, pre, back + 1, row + ')');
        }
    }
};

int main() {
    int n;
    cin >> n;

    Solution S;
    vector<string> ans = S.generateParenthesis(n);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    
    return 0;
}