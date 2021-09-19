/*
 * @Author: your name
 * @Date: 2021-02-28 10:19:11
 * @LastEditTime: 2021-02-28 10:44:05
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /LeetCode/12_整数转罗马数字.cpp
 */
#include <iostream>
#include <string>
using namespace std;

// 想法：用while循环，每次先判断该数是不是特例，如果不是，则判断该数是否大于给定数值，
//  也许可以用递归？

// 一次通过！
// 思路没问题，不过写第一遍时没有把特例加入到list中，使得像1994这样的数转换成了一大长串，应该注意！
const int number_list[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
const string symbols[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD","D", "CM", "M"};

class Solution {
public:
    string intToRoman(int num) {
        if (num < 1)
        {
            return "";
        }
        switch (num)
        {
        case 4:
            return "IV";
            break;
        case 9:
            return "IX";
            break;
        case 40:
            return "XL";
            break;
        case 90:
            return "XC";
            break;
        case 400:
            return "CD";
            break;
        case 900:
            return "CM";
            break;
        default:
            break;
        }
        for (int i = 12; i >= 0; i--)
        {
            if (num >= number_list[i])
            {
                return symbols[i] + intToRoman(num - number_list[i]);
            }
        }
        return "";
    }
};

int main(){
    Solution S;
    int number;
    cin >> number;
    string s = S.intToRoman(number);
    cout << s << endl;
    return 0;
}