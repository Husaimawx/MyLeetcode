#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        int mid;
        int min_num = INT_MAX;
        while (l <= r) {
            // cout << "l " << l << " r " << r <<endl;
            mid = l + (r-l)/2;
            if (nums[mid] < min_num) {
                min_num = nums[mid];
            }
            if (nums[l] == nums[mid]) {
                l ++;
            }
            else if (nums[mid] <= nums[r]) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return min_num;
    }
};

int main() {
    return 0;
}