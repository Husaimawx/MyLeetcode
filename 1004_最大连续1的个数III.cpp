#include <iostream>
#include <vector>
using namespace std;

// 滑动窗口

class Solution {
public:
    int longestOnes(vector<int>& nums, int K) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int cnt_0 = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            r++;
            if (nums[i] == 0) {
                cnt_0 ++;
            }
            if (cnt_0 > K) {
                if (nums[l] == 0) {
                    cnt_0 --;
                }

                l ++;
            }
            
            ans = max(ans, r - l);
        }
        return ans;
    }
};