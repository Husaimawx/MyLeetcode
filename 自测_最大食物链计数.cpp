#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int * in_cnt;
int * out_cnt;
int * memory;

int dfs(int pos, vector<vector<int> >& out) {
    if (memory[pos] != 0) {
        return memory[pos];
    }
    int cnt = 0;
    if (out_cnt[pos] == 0) {    
        return 1;
    }
    vector<int> temp = out[pos];
    for (int i = 0; i < temp.size(); i++) {
        cnt = (cnt + dfs(temp[i], out))% 80112002;
    }
    memory[pos] = cnt;
    return memory[pos];
}

int main () {
    scanf("%d %d", &n, &m);
    in_cnt = new int[n];
    out_cnt = new int[n];
    memory = new int[n];
    memset(in_cnt, 0, sizeof(int) * n);
    memset(out_cnt, 0, sizeof(int) * n);
    memset(memory, 0, sizeof(int) * n);

    vector<vector<int> > in(n);
    vector<vector<int> > out(n);
    int a, b;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        in_cnt[b-1] ++;
        out_cnt[a-1] ++;
        in[b-1].push_back(a-1);
        out[a-1].push_back(b-1);
    }
    int ans = 0;
    for (int i = 0; i < n; i ++) {
        if (in_cnt[i] == 0)
        {
            ans = (ans + dfs(i, out)) % 80112002;
        }
    }
    cout << ans << endl;
    return 0;
}

