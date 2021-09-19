#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

// 算出目标值，然后用dp[i][j]找前i个数中和为j的数目
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int diff = sum - target;
        if (diff < 0 || diff % 2 == 1) return 0;
        int neg = diff / 2;
        vector<vector<int> > dp(n+1, vector<int>(neg+1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            int temp = nums[i-1];
            for (int j = 0; j <= neg; j++) {
                dp[i][j] = dp[i-1][j];
                if (j >= temp) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - temp]);
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += dp[i][neg];
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= neg; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return ans;
    }
};