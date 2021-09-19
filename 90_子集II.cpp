#include <iostream>
#include <string.h>
#include <sstream>
#include <vector>
using namespace std;

// 这道题和78.子集那道题很像，都是找子集，但是这道题牵扯到重复元素处理。
// 首先，找子集就是说对其中的每一个元素考虑取或者不取两种情况，所以还是用递归回溯法。
// 难点在于处理重复元素
// 判断当前元素之前是否取过，因为递归逻辑是先push后pop，如果在它前面的元素都没被取，就说明之前的元素已经pop过了，那它就也不取了，直接跳过。

// 题不难，但写的时候浪费了时间，还忘记排序了。。。

class Solution {
public:
    vector<vector<int> > ans;
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> cur;
        vector<bool> chosen;
        for (int i = 0; i < nums.size(); i++)
        {
            chosen.push_back(false);
        }
        
        digui(nums, 0, cur, chosen);
        return ans;
    }
    void digui(vector<int>& nums, int pos, vector<int>& cur, vector<bool>& chosen) {
        if (pos == nums.size())
        {
            ans.push_back(cur);
            return;
        }

        if (pos > 0 && nums[pos] == nums[pos-1] && chosen[pos - 1] == false)
        {
            digui(nums, pos + 1, cur, chosen);
            return;
            
        }
        
        cur.push_back(nums[pos]);
        chosen[pos] = true;
        digui(nums, pos + 1, cur, chosen);
        cur.pop_back();
        chosen[pos] = false;
        digui(nums, pos + 1, cur, chosen);
    }
};


    
int main() {
    string input;
    cin >> input;
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == ',')
        {
            input[i] = ' ';
        }
    }
    vector<int> nums;
    istringstream output(input);
    string number;
    while (output >> number)
    {
        nums.push_back(atoi(number.c_str()));
    }
    
    Solution S;
    vector<vector<int> > ans = S.subsetsWithDup(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " " ;
        }
        
        cout << endl;
    }
    
    return 0;
}