#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

// dp[i][j] 前i个数中能否取到和为j，0-1背包
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) return false;
        int target = sum / 2;
        vector<vector<bool> > dp(n + 1, vector<bool>(target+1, false));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                dp[i][j] = dp[i-1][j] || j >= nums[i-1] &&dp[i-1][j - nums[i - 1]];
            }
        }
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j<= target; j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return dp[n][target];
    }
};