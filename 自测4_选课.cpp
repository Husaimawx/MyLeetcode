#include <iostream>
#include <vector>
using namespace std;

int N, M;
const int MAXN = 305;
int parent[MAXN];
vector<int> children[MAXN];
int p[MAXN];
int dp[MAXN][MAXN]; // 从树i的子树中选j个课的最大学分

void dfs(int root, int cnt) {
    vector<int> cs = children[root];
    for (int i = 0; i < cs.size(); i++) {
        int c = cs[i];
        for (int j = cnt + 1; j <= M + 1; j++) {
            dp[c][j] = dp[root][j - 1] + p[c];
        }
        dfs(c, cnt + 1);
        for (int j = cnt + 1; j <= M + 1; j++) {
            dp[root][j] = max(dp[root][j], dp[c][j]);
        }
    }
}

int main () {
    cin >> N >> M;
    int k, s;
    for (int i = 1; i <= N; i++) {
        cin >> k >> s;
        parent[i] = k;
        children[k].push_back(i);
        p[i] = s;
    }
    for (int i = 0; i <= M+2; i++) {
        dp[0][i] = 0;
    }
    dfs(0, 1);
    // for (int i = 0; i <= N; i++) {
    //     for (int j = 0; j <= M + 1; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[0][M + 1] << endl;
    return 0;
}