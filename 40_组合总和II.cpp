#include <iostream>
#include <string.h>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > res;
        vector<int> row;
        
        backtrack(candidates, row, target, 0, 0, res);
        return res;
    }

    void backtrack(vector<int>& candidates, vector<int>& row, int target, int pos, int sum, vector<vector<int> >& res) {
        if (sum == target)
        {
            res.push_back(row);
            return;
        }
        // 不能重复取
        for (int i = pos; i < candidates.size(); i++)
        {
            // 结果也不能重复，相同的数只取第一个
            if (i > pos && candidates[i] == candidates[i-1])
            {
                continue;
            }
            
            int current = candidates[i];
            if (sum + current <= target)
            {
                row.push_back(current);
                backtrack(candidates, row, target, i + 1, sum + current, res);
                row.pop_back();
            }
            else {
                break;
            }
        }
    }
};

// candidates = [10,1,2,7,6,1,5], target = 8,
int main() {
    vector<int> nums;
    string candidates;
    cin >> candidates;
    for (int i = 0; i < candidates.length(); i++)
    {
        if (candidates[i] == ',')
        {
            candidates[i] = ' ';
        }
    }
    istringstream out(candidates);
    string s;
    while (out >> s)
    {
        nums.push_back(atoi(s.c_str()));
    }
    
    int target;
    cin >> target;

    Solution S;
    vector<vector<int> > res = S.combinationSum2(nums, target);
    
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
        
    }
    
    return 0;
}
