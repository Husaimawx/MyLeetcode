#include <iostream>
#include <string.h>
#include <sstream>
#include <vector>
using namespace std;


// 难点：去重
// 方法： 先排序，只有当visit nums[i-1]之后我们才去visit nums[i]
class Solution {
    vector<vector<int> > ans;
    int* visited; 
public:
    vector<vector<int> > permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> row;
        visited = new int[nums.size()];
        memset(visited, 0, sizeof(int) * nums.size());
        digui(nums, 0, row);
        return ans;
    }
    void digui(vector<int>& nums, int pos, vector<int> row) {
        if (pos == nums.size())
        {
            ans.push_back(row);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            // 去重
            if (visited[i] || (i > 0 && nums[i] == nums[i-1] && nums[i-1] == 0))
            {
                continue;
            }
            
            visited[i] = 1;
            row.push_back(nums[i]);
            digui(nums, pos + 1, row);
            row.pop_back();
            visited[i] = 0;   
        }
        
        
    }
};

int main(){
    string input;
    cin >> input;
    vector<int> nums;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == ',')
        {
            input[i] = ' ';
        }
    }
    istringstream out(input);
    string s;
    while(out >> s) {
        nums.push_back(atoi(s.c_str()));
    }
    
    Solution S;
    vector<vector<int> > ans = S.permute(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
        
    }
    
    return 0;
}