#include <iostream>
#include <string.h>
#include <sstream>
#include <vector>
using namespace std;

// 排列：回溯
// 不含重复，用visited记录

class Solution {
    vector<vector<int> > ans;
    int* visited; 
public:
    vector<vector<int> > permute(vector<int>& nums) {
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
            if (visited[i] == 0)
            {
                visited[i] = 1;
                row.push_back(nums[i]);
                digui(nums, pos + 1, row);
                row.pop_back();
                visited[i] = 0;   
            }
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