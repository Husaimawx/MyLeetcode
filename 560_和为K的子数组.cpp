#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int pre[20005];
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        pre[0] = 0;
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + nums[i];
        }
        int ans = 0;
        for (int l = 0; l < n; l++) {
            for (int r = l; r < n; r++) {
                if (pre[r+1] - pre[l] == k ) {
                    ans++;
                }
            }
        }
        return ans;
    }
};