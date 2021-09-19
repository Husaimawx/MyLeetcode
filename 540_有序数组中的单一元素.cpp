#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 二分

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int lo = 0;
        int hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (mid % 2 == 1) mid--;
            if (nums[mid] == nums[mid + 1]) {
                lo = mid + 2;
            } else {
                hi = mid - 1;
            }
        }
        return nums[lo];
    }
};