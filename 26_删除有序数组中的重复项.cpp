#include <iostream>
#include <string.h>
#include <sstream>
#include <vector>
using namespace std;

// 输入：nums = [1,1,2]
// 输出：2, nums = [1,2]
// 解释：函数应该返回新的长度 2 ，并且原数组 nums 的前两个元素被修改为 1, 2 。不需要考虑数组中超出新长度后面的元素。

// 最开始想到了重复元素往后交替换，但是有一个点过不去
// 看题解发现可以用双指针，快指针就正常往前走，慢指针记录下一次要插入的位置
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
        {
            return 0;
        }
        
        int fast;
        int slow = 1;
        for (fast = 1; fast < nums.size(); fast++)
        {
            if (nums[fast] != nums[fast - 1])
            {
                nums[slow] = nums[fast];
                slow ++;
            }
            
        }
        printList(nums);
        return slow;
    }
    void printList(vector<int>& nums)  {
        for (int i = 0; i < nums.size(); i++)
        {
            cout << nums[i] <<  " ";
        }
        cout << endl;
    }
};

int main() {
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
    istringstream out(input);
    string n;
    vector<int> nums;
    while (out >> n)
    {
        nums.push_back(atoi(n.c_str()));
    }
    Solution S;
    cout << S.removeDuplicates(nums) << endl;  

    
    return 0;
}