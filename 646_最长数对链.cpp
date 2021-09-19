#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int> >& pairs) {

        int n = pairs.size();
        if (n == 1) return 1;

        sort(pairs.begin(), pairs.end());
        vector<int> dp (n+1, 0);
        
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i-1];
            for (int j = 1; j < i; j++) {
                if (pairs[i-1][0] > pairs[j-1][1]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        // for (int i = 0; i <= n; i++) cout << dp[i] << " ";
        // cout << endl;
        return dp[n];
    }
};