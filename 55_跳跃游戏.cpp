#include <iostream>
#include <string.h>
#include <sstream>
#include <vector>
using namespace std;


// 想到了递归，想到了从后向前，但是复杂度太高
// 其实很简单，只需要用贪心法维护最远距离，一次遍历，实时更新，找当前所有元素所能到达的最远的距离

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_dis = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i <= max_dis)
            {
                max_dis = max(max_dis, i + nums[i]);
                if (max_dis >= nums.size()-1)
                {
                    return true;
                }
            }
        }
        return false;  
    }
};

// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         if (nums.size() == 1)
//         {
//             return true;
//         }
        
//         vector<int> ans = findPre(nums.size() - 1, nums);
//         if (reachFirst(ans))
//         {
//             return true;
//         }
        
        
//         while (ans.size())
//         {
//             vector<int> copy_ans;
            
//             for (int i = 0; i < ans.size(); i++)
//             {
//                 vector<int> temp_ans = findPre(ans[i], nums);
//                 if (reachFirst(temp_ans))
//                 {
//                     return true;
//                 }
//                 for (int i = 0; i < temp_ans.size(); i++)
//                 {
//                     copy_ans.push_back(temp_ans[i]);
//                 }
//             }
//             ans = copy_ans;
//         }
        
//         return false;
//     }

//     vector<int> findPre(int pos, vector<int>& nums) {
//         cout << "find pre " << pos << endl;
//         vector<int> ans;
//         if (pos >= nums.size())
//         {
//             return ans;
//         }
        
//         for (int i = 0; i < pos; i++)
//         {
//             if (nums[i] + i >= pos)
//             {
//                 ans.push_back(i);
//             }
            
//         }
//         for (int i = 0; i < ans.size(); i++)
//         {
//             cout << ans[i] << " ";
//         }
//         cout << endl;
//         return ans;
//     }

//     bool reachFirst(vector<int>& ans) {
//         for (int i = 0; i < ans.size(); i++)
//         {
//             if (ans[i] == 0)
//             {
//                 return true;
//             }
//         }
//         return false;
//     }
// };

// 输入：nums = [2,3,1,1,4]
// 输出：true

int main() {
    vector<int> nums;
    string input;
    cin >> input;
    input = input.substr(1, input.length() - 2);
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == ',')
        {
            input[i] = ' ';
        }
    }
    istringstream output(input);
    string num;
    while (output >> num)
    {
        nums.push_back(atoi(num.c_str()));
    }
    
    Solution S;
    cout << S.canJump(nums) << endl;;
    return 0;
}