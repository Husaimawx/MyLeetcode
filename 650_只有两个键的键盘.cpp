#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSteps(int n) {
        vector<int> dp (n+1, 0);
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2; i <= n; i++) {
            dp[i] = i;
            for (int j = 2; j <= i/2; j++) {
                if (i % j == 0) {
                    dp[i] = dp[j] + dp[i/j];
                    break;
                }
            }
        }
        // for (int i = 0; i <= n; i++) {
        //     cout << dp[i] << " ";
        // }
        // cout << endl;
        return dp[n];
    }
    
};