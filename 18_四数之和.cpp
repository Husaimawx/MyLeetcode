#include <iostream>
#include <sstream>
#include <vector>
using namespace std;


// 重点在【剪枝】
// 具体实现时，还可以进行一些剪枝操作：

// 在确定第一个数之后，如果 \textit{nums}[i]+\textit{nums}[i+1]+\textit{nums}[i+2]+\textit{nums}[i+3]>\textit{target}nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target，
// 说明此时剩下的三个数无论取什么值，四数之和一定大于 \textit{target}target，因此退出第一重循环；
// 在确定第一个数之后，如果 \textit{nums}[i]+\textit{nums}[n-3]+\textit{nums}[n-2]+\textit{nums}[n-1]<\textit{target}nums[i]+nums[n−3]+nums[n−2]+nums[n−1]<target，
// 说明此时剩下的三个数无论取什么值，四数之和一定小于 \textit{target}target，因此第一重循环直接进入下一轮，枚举 \textit{nums}[i+1]nums[i+1]；
// 在确定前两个数之后，如果 \textit{nums}[i]+\textit{nums}[j]+\textit{nums}[j+1]+\textit{nums}[j+2]>\textit{target}nums[i]+nums[j]+nums[j+1]+nums[j+2]>target，
// 说明此时剩下的两个数无论取什么值，四数之和一定大于 \textit{target}target，因此退出第二重循环；
// 在确定前两个数之后，如果 \textit{nums}[i]+\textit{nums}[j]+\textit{nums}[n-2]+\textit{nums}[n-1]<\textit{target}nums[i]+nums[j]+nums[n−2]+nums[n−1]<target，
// 说明此时剩下的两个数无论取什么值，四数之和一定小于 \textit{target}target，因此第二重循环直接进入下一轮，枚举 \textit{nums}[j+1]nums[j+1]。

class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        vector<vector<int> > res;
        
        if (nums.size() < 4)
        {
            return res;
        }

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 3; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            
            if (nums[0] > 1000000000)
            {
                return res;
            }
            

            if (nums[i] + nums[i+1] + nums[i+2] +  nums[i + 3] > target)
            {
                break;
            }

            if (nums[i] + nums[nums.size() - 1] + nums[nums.size() - 2] + nums[ nums.size() -3] < target)
            {
                continue;
            }

            
            
            
            for (int j = i + 1; j < nums.size() - 2; j++)
            {
                if (j > i+1  && nums[j] == nums[j - 1])
                {
                    continue;
                }

                if (nums[i] + nums[j] + nums[j+1] +  nums[j+2] > target)
                {
                    break;
                }

                if (nums[i] + nums[j] + nums[nums.size() - 1] + nums[ nums.size() -2] < target)
                {
                    continue;
                }


                int c_pos = j + 1;

                int d_pos = nums.size() - 1;
                
                while (c_pos < d_pos)
                {
                    int sum = nums[i] + nums[j] + nums[c_pos] + nums[d_pos];
                    
                    if (sum == target)
                    {
                        vector<int> o;
                        o.push_back(nums[i]);
                        o.push_back(nums[j]);
                        o.push_back(nums[c_pos]);
                        o.push_back(nums[d_pos]);
                        res.push_back(o);
                        while (c_pos < d_pos && nums[c_pos] == nums[c_pos + 1]) {
                            c_pos++;
                        }
                        c_pos++;
                        while (c_pos < d_pos && nums[d_pos] == nums[d_pos - 1]) {
                            d_pos--;
                        }
                        d_pos--;
                    }
                    else if (sum > target) {
                        while (c_pos < d_pos && nums[d_pos] == nums[d_pos - 1]) {
                            d_pos--;
                        }
                        d_pos--;
                    }
                    else if (sum < target) {
                        while (c_pos < d_pos && nums[c_pos] == nums[c_pos + 1]) {
                            c_pos++;
                        }
                        c_pos++;
                    }
                }
            }
        }
        return res;
    }
};

// 输入：nums = [1,0,-1,0,-2,2], target = 0
// 输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
// [2,2,2,2,2] 8

int main () {
    vector<int> nums;
    string input;
    cin >> input;
    input = input.substr(1, input.size() - 2);
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == ',')
        {
            input[i] = ' ';
        }
    }
    istringstream out(input);
	string str;
	while (out >> str){
        int i = atoi(str.c_str());
        nums.push_back(i);
	}

    // for (int i = 0; i < nums.size(); i++)
    // {
    //     cout << nums[i] << endl;
    // }
    int target;
    cin >> target;

    Solution S;
    vector<vector<int> > ans = S.fourSum(nums, target);

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
