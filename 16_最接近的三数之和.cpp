/*
 * @Author: your name
 * @Date: 2021-02-28 14:26:17
 * @LastEditTime: 2021-07-22 07:55:15
 * @LastEditors: Wenxuan Ma
 * @Description: In User Settings Edit
 * @FilePath: /LeetCode/16_最接近的三数之和.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//  想法：
//      和上一道题不同的是，这题要找最接近的，并且答案唯一。
//      首先应该排序，最接近也就是说差值最小，
//      再次考虑动态规划，但是hp[i][j][k]是固定的，无法求解
//      考虑优化三重循环，最外层循环依然不变，内层的两重循环需要更改，
//      核心在于：如果a+b+c≥target，则左移c，如果a+b+c<target，则右移b。
//      另一个关键点在于，何时更新？
//      原本的想法是在最接近的左右两侧更新，但为了写代码方便，采用每次都更新的方式。

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int _target) {
        sort(nums.begin(), nums.end());
        int dis = 99999; 
        int res = 99999;
        for (int a = 0; a < nums.size(); a++){
            int b = a + 1;
            int c = nums.size() - 1;
            while (b < c){
                int sum = nums[a] + nums[b] + nums[c];
                
                if (sum == _target){
                    return _target;
                }

                if (abs(sum - _target) < dis){
                    dis = abs(sum - _target);
                    res = sum;
                }
                
                if (sum > _target) {
                    c--;
                }
                else {
                    b++;
                }
            }
        }
        return res;
    }
};

int main(){
    Solution S;
    vector<int> numbers;
    string s;
    cin >> s;
    int target;
    cin >> target;
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
    cout << S.threeSumClosest(numbers, target) << endl;;
    
    return 0;
}