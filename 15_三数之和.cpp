#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//  普通方法O(n^3)，肯定不行
//  似乎有点像是动态规划，但是传递什么呢？
//  要找出所有的

//  还是需要枚举，但是需要优化
//  首先解决重复的问题，要避免重复，需要先对数组排序，这样保证 a < b < c
//  并且同一重循环的前后两次跳跃不能相同

//  然后再降复杂度，对第二重和第三重循环使用双指针，也就是说b增大的同时减小c，这样合才有可能继续为0

//  也就是说循环减到了两重，b和c共用了第二重循环

//  复杂度O(n^2)

//  感受：
//      要考虑怎么去优化，即使同样是三重循环，也有很大的优化空间。
//      排序、同一个循环里跳过相同的、双指针
class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<int> group;
        vector<vector<int> > ans;
        sort(nums.begin(), nums.end());

        for (int a = 0; a < nums.size(); a++)
        {
            if (a > 0 && nums[a] == nums[a-1])
            {
                continue;
            }
            int c = nums.size() - 1;
            int target = -nums[a];
            for (int b = a + 1; b < nums.size(); b++)
            {
                if (b > a + 1 && nums[b] == nums[b-1])
                {
                    continue;
                }
                while (b < c && nums[b] + nums[c] > target)
                {
                    c--;
                }
                
                if (b == c)
                {
                    break;
                }

                if (nums[b] + nums[c] == target)
                {
                    vector<int> temp;
                    temp.push_back(nums[a]);
                    temp.push_back(nums[b]);
                    temp.push_back(nums[c]);
                    ans.push_back(temp);
                }    
            }
        }
        
        return ans;
    }
};

int main(){
    Solution S;
    vector<int> numbers;
    string s;
    cin >> s;
    s = s.substr(1, s.size() - 1);
    int pos = s.find(',');
    while (pos != s.npos)
    {
        string temp = s.substr(0,pos);
        numbers.push_back(atoi(temp.c_str()));
        s = s.substr(pos+1, s.size());
        pos = s.find(',');
    }
    numbers.push_back(atoi(s.c_str()));
    S.threeSum(numbers);
    
    return 0;
}