#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int> > ans;
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int cur_sum = 0;
        vector<int> cur_ans;
        digui(candidates, target, 0, 0, cur_ans, 0);
        return ans;
    }
    void digui(vector<int> & candidates, int& target, int cur_sum, int pos, vector<int> cur_ans, int cur_max_pos) {
        if (cur_sum > target) return;
        if (cur_sum == target) {
            ans.push_back(cur_ans);
            return;
        }
        // 可以重复取，但是结果是组合而不是排列，所以每次都要从当前最大的数开始遍历
        for (int i = cur_max_pos; i < candidates.size(); i++) {
            cur_ans.push_back(candidates[i]);
            digui(candidates, target, cur_sum + candidates[i], pos + 1, cur_ans, i);
            cur_ans.pop_back();
        }
    }
};



int main () {

    return 0;
}