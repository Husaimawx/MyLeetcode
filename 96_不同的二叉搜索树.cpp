#include <iostream>
using namespace std;

// Again，想到了动态规划，但是依然不知道怎么规划
// 看了题解
// 因为对于一个根确定的二叉搜索树，它的个数 = 左子树的个数 * 右子树的个数，可以将原问题化解为两个子问题的乘积
// 令G(n) = sum(F(i,n) i:1~n)： n个节点得到的二叉搜索树的个数
// 令F(i,n) = G(i-1)* G(n-i)：n个节点且以i为根的二叉搜索树的个数

// 一看题解觉得好简单，怎么自己就是想不出来

class Solution {
public:
    int *dp;
    int numTrees(int n) {
        dp = new int [n+1];
        memset(dp, 0, sizeof(int)*(n+1));
        dp[0] = 1; //需要乘
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                dp[i] += dp[j-1] * dp[i-j];
            }
        }
        // for (int i = 0; i <= n; i++)
        // {
        //     cout << dp[i] << " ";
        // }
        // cout << endl;
        
        return dp[n];
    }
};


int main () {
    int n;
    cin >> n;
    Solution S;
    cout << S.numTrees(n) << endl;

    return 0;
}