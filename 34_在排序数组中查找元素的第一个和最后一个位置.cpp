#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};
        int lower = lower_bound(nums, target);
        int upper = upper_bound(nums, target) -1;
        if (lower == nums.size() || nums[lower] != target) {
            return {-1, -1};
        }
        return {lower, upper};
    }
    int lower_bound(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, mid;
        while(l <= r) {
            mid = (l+r)/2;
            if (nums[mid] >= target) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return l;
    }
    int upper_bound(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, mid;
        while(l <= r) {
            mid = (l+r)/2;
            if (nums[mid] > target) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return l;
    }
};