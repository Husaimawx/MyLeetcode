#include <iostream>
#include <vector>
using namespace std;

// 宽排序，高最大递增子序列

class Solution {
public:
    int maxEnvelopes(vector<vector<int> >& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end());
        
        vector<int> dp(n+1, 1);
        int ans = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                if (envelopes[i-1][0] > envelopes[j-1][0] && envelopes[i-1][1] > envelopes[j-1][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    ans = max(dp[i], ans);
                }
            }
        }

        // for (int i = 0; i < n; i++) {
        //     cout << envelopes[i][0] << " " << envelopes[i][1] << endl;;
        // }
        // cout << endl;
        return ans;
    }
};