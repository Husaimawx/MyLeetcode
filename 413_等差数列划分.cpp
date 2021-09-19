#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 持续更新diff

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return 0;
        }

        vector<int> dp(n, 0);

        int ans = 0;
        int diff = nums[1] - nums[0];
        for (int i = 2; i < n; i++) {
            if (nums[i] - nums[i-1] == diff) {
                dp[i] = dp[i-1] + 1;
                ans += dp[i];
            }
            else {
                dp[i] = 0;
                diff = nums[i] - nums[i-1];
            }
        }
        return ans;
    }
};