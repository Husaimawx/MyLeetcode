#include <iostream>
#include <vector>
using namespace std;

// 超时
// sum[i]用来存以i为根时的所有子节点数量，用dfs算
// dp 用递归求，dp[i] = sum(dp[target][root] + sum[target])

class Solution {
public:
    vector<int> e[10005];
    int sum[10005];
    void dfs(int root, int source) {
        sum[root] = 1;
        for (int i = 0; i < e[root].size(); i ++) {
            int target = e[root][i];
            if (target != source) {
                dfs(target, root);
                sum[root] += sum[target]; 
            }
        }
    }

    int dp(int root, int source) {
        // cout << "root " << root << endl;
        int ans = 0;
        for (int j = 0; j < e[root].size(); j++) {

            int target = e[root][j];
            // cout << "target " << target << endl;
            if (target != source) 
                ans += dp(target, root) + sum[target];
        }
        // cout << "ans " << root  << " " << ans << endl;
        return ans;
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int> >& edges) {
        int u, v;
        for (int i = 0; i < n-1; i++) {
            u = edges[i][0];
            v = edges[i][1];
            e[u].push_back(v);
            e[v].push_back(u);
        }

        vector<int> ans;
        for (int i = 0; i< n; i ++){
            dfs(i,-1);
            ans.push_back(dp(i, -1));
        }
        return ans;
    }
};