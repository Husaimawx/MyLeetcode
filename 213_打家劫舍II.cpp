#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return nums[0];
        }
        if (n == 2) {
            return max(nums[0], nums[1]);
        }

        vector<int> dp_1(n-1, 0);
        vector<int> dp_2(n-1, 0);
        
        dp_1[0] = nums[0];
        dp_1[1] = max(nums[0], nums[1]);

        dp_2[0] = nums[1];
        dp_2[1] = max(nums[1], nums[2]);

        for (int i = 2; i < n - 1; i++) {
            dp_1[i] = max(dp_1[i-1], dp_1[i-2] + nums[i]);
        }

        for (int i = 2; i < n-1; i++ ){
            dp_2[i] = max(dp_2[i-1], dp_2[i-2] + nums[i+1]);
        }

        return max(dp_1[n-2], dp_2[n-2]);
    }
};