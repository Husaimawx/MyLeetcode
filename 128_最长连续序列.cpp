#include <iostream>
#include <string.h>
#include <sstream>
#include <vector>
#include <set>
using namespace std;

// 这道题一上来也想用dp，但想了半天完全没法dp，看了眼题解，要用set
// 思路在于，把所有数先放到set里，达到去重的效果，然后对set里的每一个数，判断它的前一个数是不是在set里，如果在的话就不管这个数。
// 找到一个数它的前继不在set里之后，就从这个数开始一直找，记录个数。

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> num_set;
        for (int i = 0; i < nums.size(); i++)
        {
            num_set.insert(nums[i]);
        }
        int ans = 0;
        for (set<int>::iterator num = num_set.begin(); num != num_set.end(); num ++ )
        {
            int temp = *num;
            if (!num_set.count(temp - 1)) {
                int cur = 1;

                while (num_set.count(temp + 1)) {
                    temp += 1;
                    cur += 1;
                }

                if (cur > ans)
                {
                    ans = cur;
                }
            }
        }

        // for (int i = 0; i < nums.size(); i++)
        // {
        //     cout << nums[i] << " ";
        // }
        // cout << endl;
        
        return ans;
    }
};

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
    string temp;
    while (output >> temp)
    {
        nums.push_back(atoi(temp.c_str()));
    }
    Solution S;
    cout << S.longestConsecutive(nums) << endl;
    
    return 0;
}