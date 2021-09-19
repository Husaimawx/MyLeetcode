#include <iostream>
#include <string.h>
#include <vector>
#include <sstream>
using namespace std;


// 本来想用递归回溯，但是遇到了问题，而且似乎复杂度比较高
// 看了解析，很简单
// 只用一次遍历，在遍历过程中通过两个变量来记录上次的最远和这次的最远
// cur_far记录跳一次可以跳到的最远距离
// 如果i到了上次能跳的最远距离，就必须要跳一次step++
class Solution {
public:
    int jump(vector<int>& nums) {
        int step = 0;

        int cur_far = 0;
        int pre_far = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            cur_far = max(cur_far, i + nums[i]);

            if (i == pre_far)
            {
                pre_far = cur_far;
                step ++;
            }
            
        }
        return step - 1;
    }
};
// int jump(vector<int>& nums) {
//     minStep = 99999999;
//     digui(nums, 0, 0);
//     return minStep;
// }

// void digui(vector<int>& nums, int pos, int step) {
//     cout << "pos " << pos <<  endl;
//     if (pos >= nums.size())
//     {
//         return;
//     }
    
//     if (pos == nums.size() - 1)
//     {
//         if (step < minStep)
//         {
//             minStep = step;
//         }
//         return;
//     }
    
//     for (int i = 1; i <= nums[pos]; i++)
//     {
//         int newPos = pos + i;
//         cout << "newPos" << newPos << endl;
//         if (newPos < nums.size())
//         {
//             digui(nums, newPos, step + 1);
//         }
//         else {
//             return;
//         }
//     }
    
// }
// nums = [2,3,1,1,4]

int main() {
    vector<int> nums;

    string input;
    cin >> input ;
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == ',')
        {
            input[i] = ' ';
        }
    }
    istringstream output(input);
    string s;
    while (output >> s)
    {
        nums.push_back(atoi(s.c_str()));
    }
    
    Solution S;
    cout << S.jump(nums) << endl;;
    return 0;
}