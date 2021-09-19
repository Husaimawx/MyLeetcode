#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <string.h>
using namespace std;

int n;
int points[6005];
bool has_father[6005];
vector<vector<int> > children(6005);

unordered_map<int, int> chose_v;
unordered_map<int, int> not_chose_v;

void dfs(int root) {
    vector<int> cs = children[root];
    
    chose_v[root] = points[root];
    for (int i = 0; i < cs.size(); i++) {
        dfs(cs[i]);
        chose_v[root] += not_chose_v[cs[i]];
        not_chose_v[root] += max(chose_v[cs[i]], not_chose_v[cs[i]]);
    }
}

int main () {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> points[i];
    }
    
    memset(has_father, false, sizeof(has_father));
    
    int l, k;
    for (int i = 1; i < n; i++) {
        cin >> l >> k;
        children[k].push_back(l);

        has_father[l] = true;
    }

    int root = 0;
    for (int i = 1; i <= n; i++) {
        if (!has_father[i]) {
            root = i;
            break;
        }
    }
    dfs(root);
    cout << max(chose_v[root], not_chose_v[root]) << endl;;
    

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 0; j < children[i].size(); j++) {
    //         cout << children[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}

