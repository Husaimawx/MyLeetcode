#include <iostream>
#include <string.h>
#include <cstdio>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>
using namespace std;

void getAns(int N, int *nums, int ** connects) {

    if (N < 1) return;
    if (N == 1) {
        cout << 1 << endl;
        cout << nums[0] << endl;
        return;
    }
    
    int * dp = new int[N+1];
    memset(dp, 0, sizeof(int) * (N+1));
    
    unordered_map<int, int> map;
    dp[1] = nums[0];
    for (int i = 2; i <= N; i++) {
        
        int pre = 0;
        for (int j = 0; j < N; j++) {
            if (connects[j][i-1]){
                if (dp[j+1] > pre) {
                    map[i] = j+1;
                    pre = dp[j+1];
                }
            }
        }
        dp[i] = nums[i-1] + pre;
    } 
    int ans = 0;
    int max_pos = 0;
    for (int i = 1; i <= N; i++) {
        if (dp[i] > ans) {
            max_pos = i;
            ans = dp[i];
        }
    }
    vector<int> path;
    path.push_back(max_pos);
    while (map[max_pos] != 0)
    {
        max_pos = map[max_pos];
        path.push_back(max_pos);
    }
    
    reverse(path.begin(), path.end());
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << " ";
    }
    cout << endl;
    cout << ans << endl;
    return;
}

int main() {
    int N;
    scanf("%d", &N);
    int* nums = new int [N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &nums[i]);
    }

    int ** connects = new int* [N];
    for (int i = 0; i < N; i++) {
        connects[i] = new int[N];
        memset(connects[i], 0, sizeof(int) * N);
    }
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            cin >> connects[i][j];
        }
    }
    
    // for (int i = 0; i<N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         cout << connects[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    getAns(N, nums, connects);
    return 0;
}