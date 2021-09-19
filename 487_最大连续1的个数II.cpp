#include <vector>
#include <iostream>
using namespace std;

// dp[i][j]表示剩余翻转次数为j时的最大连续个数

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;
        vector<vector<int> > dp(n+1, vector<int>(2, 0));
        int ans = 0;
        dp[0][0] = nums[0];
        dp[0][1] = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] == 0) {
                dp[i][0] = 0;
                dp[i][1] = dp[i-1][0] + 1;
            }
            else {
                dp[i][0] = dp[i-1][0] + 1;
                dp[i][1] = dp[i-1][1] + 1;
            }
            ans = max(ans, max(dp[i][0], dp[i][1]));
        }
        return ans;
    }
};