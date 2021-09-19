#include <vector>
#include <deque>
using namespace std;

// dq存当前窗口内最大的位置

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        for (int i = 0; i < nums.size(); i ++) {
            // 右移
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }
            // 
            while(!dq.empty() &&  nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if (i >= k-1) {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};