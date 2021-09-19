#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        vector<int> dp(n + 1, 1);
        sort(nums.begin(), nums.end());
        int end_p = 1;
        int max_dp = 0;
        int max_val = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                if (nums[i-1] % nums[j-1] == 0) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            if (dp[i] > max_dp) {
                max_dp = dp[i];
                end_p = i;
            }
        }

        max_val = nums[end_p - 1];
        for (int i = end_p; i > 0; i--) {
            if (max_val % nums[i-1]== 0 && dp[i] == max_dp) {
                ans.push_back(nums[i-1]);
                max_val = nums[i-1];
                max_dp --;
            } 
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};