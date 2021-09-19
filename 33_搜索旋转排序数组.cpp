#include <iostream>
#include <sstream>
#include <string.h>
#include <vector>
using namespace std;

// 可以通过前后遍历的方式AC，但是复杂度还是O(n)
// 要想复杂度降到O(logn)，就得二分
// 二分的时候先判断

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = (int)nums.size();
        if (!n) {
            return -1;
        }
        if (n == 1) {
            return nums[0] == target ? 0 : -1;
        }
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) return mid;
            if (nums[0] <= nums[mid]) {
                // 左边是有序的
                if (nums[0] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                // 右边是有序的
                if (nums[mid] < target && target <= nums[n - 1]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};
// [4,5,6,7,0,1,2]

int main() {
    string input;
    cin >> input;
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

    int target;
    cin >> target;
    
    // for (int i = 0; i < nums.size(); i++)
    // {
    //     cout << nums[i] << " " ;
    // }
    // cout << endl;
    Solution S;
    cout << S.search(nums, target) << endl;

    return 0;
}