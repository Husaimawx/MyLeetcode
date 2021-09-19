#include <iostream>
#include <vector>
using namespace std;

// 两个数组：up, down
// up[i]: 前i个数的最大摆动数列长度（nums[i-1] - nums[i-2] > 0）


class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;
        
        vector<int> up(n+1, 0);
        vector<int> down(n+1, 0);
        up[1] = 1;
        down[1] = 1;
        for (int i = 2; i <= n; i++) {
            up[i] = up[i-1];
            down[i] = down[i-1];
            if (nums[i-1] - nums[i-2] > 0)
                up[i] = max(up[i], down[i-1] + 1);
            if (nums[i-1] - nums[i-2] < 0)
                down[i] = max(down[i], up[i-1] + 1);
            
        }
        return max(up[n], down[n]);
    }
};