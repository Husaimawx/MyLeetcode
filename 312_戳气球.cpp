#include <iostream>
#include <vector>
using namespace std;

// 换成向一个密集的队列中插入气球，dp[i][j] 表示 i-j 中放满气球的最大值，遍历插入点
// 转移方程是：dp[i][j] = max(dp[i][j], nums[i] * nums[j] * nums[mid] + dp[i][mid] + dp[mid][j]);

class Solution{
public:
    
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        vector<vector<int> > dp (n+2, vector<int>(n+2, 0));
        
        for (int i = n-1; i >= 0; i--) {
            for (int j = i+2; j <= n+1; j++) {
                for (int mid = i + 1; mid < j; mid++) {
                    dp[i][j] = max(dp[i][j], nums[i] * nums[j] * nums[mid] + dp[i][mid] + dp[mid][j]);
                }
            }
        }
        return dp[0][n+1];
    }
};