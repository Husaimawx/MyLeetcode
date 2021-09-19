#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        int cur_max = 1;
        int cur_min = 1;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) {
                swap(cur_max, cur_min);
            }
            
            cur_max = max(cur_max * nums[i], nums[i]);
            cur_min = min(cur_min * nums[i], nums[i]);

            ans = max(ans, cur_max);
        }
        
        return ans;
    }
};

int main () {

    return 0;
}