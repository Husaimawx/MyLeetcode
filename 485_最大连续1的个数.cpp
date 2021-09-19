#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int>dp (n, 0);
        int ans = nums[0];
        dp[0] = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] == 1) {
                dp[i] = dp[i-1] + 1;
            }
            else {
                dp[i] = 0;
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};