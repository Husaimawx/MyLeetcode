#include <iostream>
#include <vector>
using namespace std;

// 找一个集合的子集，同样还是选或者不选的问题，每一轮过去，在终点处return
class Solution {
public:
    vector<vector<int> > ans;
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<int> cur;
        digui(nums, 0, cur);
        return ans;
    }
    void digui(vector<int>& nums, int pos, vector<int>& cur) {
        if (pos == nums.size())
        {
            ans.push_back(cur);
            return;
        }

        cur.push_back(nums[pos]);
        digui(nums, pos + 1, cur);
        cur.pop_back();
        digui(nums, pos + 1, cur);
    }
};

    
int main() {
    return 0;
}