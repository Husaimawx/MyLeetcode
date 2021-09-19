#include <iostream>
#include <string.h>
#include <sstream>
#include <vector>
using namespace std;


// 想了很久，几乎想到了，但是交换的方式错了
// 分三步：
// 第一步，从后往前，找到第一个递减元素（找不到的话就是一直递增，比如说[2,4,3,1]中的2）作为target
// 第二步，如果找到了target，从后往前，找到第一个比target大的元素，target2， 交换target和target2，则得到的后继子数组一定是递减的
// 第三部，如果没找到，排序整个数组；如果找到了，排序后续子数组（应该说是翻转，从递减变为递增）
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int max_in_suf = -1;
        int pos = 0;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (nums[i] > max_in_suf)
            {
                max_in_suf = nums[i];
            }
            if (nums[i] < max_in_suf)
            {
                pos = i;
                break;
            }
            
        }
        cout << max_in_suf << endl;
        
        cout << nums[pos] << endl;
        if (max_in_suf == nums[pos])
        {
            pos = -1;
        }
        else {
            int target = nums[pos];
            int pos_2 = 0;
            for (int i = nums.size() - 1; i >= pos; i--)
            {
                if (nums[i] > target)
                {
                    pos_2 = i;
                    break;
                }
            }
            // cout << pos_2 << endl;
            cout << nums[pos_2] << endl;
            
            nums[pos] = nums[pos_2];
            nums[pos_2] = target;
        }
        

        for (int i = pos + 1; i < nums.size(); i++)
        {
            cout << " " << nums[i] << endl;
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] > nums[j])
                {
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                }
                
            }
            
        }
        
        
    }
};

// nums = [1,2,3]
int main() {
    string input ;
    cin >> input ;
    input = input.substr(1, input.length()-2);
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == ',')
        {
            input[i] = ' ';
        }
    }
    istringstream out(input);
    string num;
    vector<int> nums;
    while (out >> num)
    {
        nums.push_back(atoi(num.c_str()));
    }

    Solution S;
    S.nextPermutation(nums);

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " " ;
    }
    cout << endl;
    // [1,3,4,2]
       
    

    return 0;
}