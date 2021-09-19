#include <iostream>
#include <vector>
using namespace std;

// 组合的问题就是取或不取的问题

class Solution {
public:
    vector<vector<int> > ans;
    vector<int> temp;
    vector<vector<int> > combinationSum3(int k, int n) {
        digui(0, 1, k, n);
        return ans;
    }
    void digui(int sum, int cur, int k, int n) {
        if (temp.size() == k && sum == n) {
            ans.push_back(temp);
            return;
        }
        if (cur > 9) return ;
        temp.push_back(cur);
        digui(sum + cur, cur + 1, k, n);
        temp.pop_back();
        digui(sum, cur + 1, k, n);
    }
};