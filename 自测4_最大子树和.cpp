#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

int n;
const int max_n = 16005;

int points[max_n];
vector<int> edges[max_n];
unordered_map<int, int> dp;

int ans;
void dfs (int root, int parent) {
    vector<int> edge = edges[root];

    dp[root] = points[root];
    for (int i = 0; i < edge.size(); i++) {
        if (edge[i] == parent) {
            continue;
        }
        dfs(edge[i], root);
        dp[root] += max(0, dp[edge[i]]);
    }
    ans = max(ans, dp[root]);
}

int main () {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> points[i];
    }
    if (n == 1) {
        cout << points[1] << endl;
        return 0;
    }

    int u, v;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    ans = INT_MIN;
    dfs(1, -1);
    cout << ans << endl;
    return 0;
}