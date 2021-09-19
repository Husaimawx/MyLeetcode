#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_map<int,int> cnt;
        int sum[10005];
        memset(sum, 0, sizeof(sum));
        int max_num = 0;
        int min_num = 10005;
        
        for (int i = 0; i < n; i++) {
            cnt[nums[i]] ++;
            max_num = max(max_num, nums[i]);
            min_num = min(min_num, nums[i]);
        }

        int length = max_num - min_num + 1;

        for (int i = 0; i < n; i++) {
            sum[nums[i] - min_num] = nums[i] * cnt[nums[i]];
            while(i + 1 < n && nums[i + 1] == nums[i]) {
                i++;
            }
        }
        // for (int i = 0; i < length; i++) {
        //     cout << sum[i] << " ";
        // }
        // cout <<endl;
        vector<int> dp(length+1, 0);
        dp[1] = sum[0];
        for (int i = 2; i <= length; i++) {
            dp[i] = max(dp[i-1], dp[i-2] + sum[i-1]);
        }
        return dp[length];
        // return 0;
    }
};