#include <iostream>
#include <vector>
using namespace std;

// 额外用一个数组count[i]存 以i结尾的最长递增子序列的个数

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, 1);
        vector<int> count(n + 1, 1);
        int max_l = 1;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                if (nums[i-1] > nums[j-1]) {
                    if(dp[j] + 1 > dp[i]){
                        count[i] = count[j];
                    }
                    else if (dp[j] + 1 == dp[i]){
                        count[i] += count[j];
                    }
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            max_l = max(max_l, dp[i]);
        }

        for (int i = 1; i <= n; i++) {
            if (dp[i] == max_l) {
                ans += count[i];
            }
        }
        return ans;
    }
};