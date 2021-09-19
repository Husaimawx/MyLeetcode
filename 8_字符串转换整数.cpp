#include <iostream>
#include <string>
#include <math.h>
using namespace std;

// 读入字符串并丢弃无用的前导空格
// 检查下一个字符（假设还未到字符末尾）为正还是负号，读取该字符（如果有）。 确定最终结果是负数还是正数。 如果两者都不存在，则假定结果为正。
// 读入下一个字符，直到到达下一个非数字字符或到达输入的结尾。字符串的其余部分将被忽略。
// 将前面步骤读入的这些数字转换为整数（即，"123" -> 123， "0032" -> 32）。如果没有读入数字，则整数为 0 。必要时更改符号（从步骤 2 开始）。
// 如果整数数超过 32 位有符号整数范围 [−231,  231 − 1] ，需要截断这个整数，使其保持在这个范围内。具体来说，小于 −231 的整数应该被固定为 −231 ，大于 231 − 1 的整数应该被固定为 231 − 1 。
// 返回整数作为最终结果。

// 感受：
// bug会非常的多，并且会有很多没想到的问题
// 一定要先想清楚，再去做

// 思路：
// 遍历字符串
// 如果不是从数字开始，分四种情况
//      空格：忽略
//      +：正数
//      -：负数
//      其他非法字符：返回0
// 当遇到数字之后，进入while循环
//      每次 乘10 + 数字
//      溢出就return
//          正负号由isPositive判断，不通过比较判断
// 从while循环跳出后考虑正负号并返回

int myAtoi(string s) {
    long MAX_NUMBER = pow(2,31) - 1;
    long MIN_NUMBER = pow(2,31) * -1;
    int n = s.length();
    bool isPositive = true;
    bool gotNumber = false;
    long long number = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            gotNumber = true;
        }

        if (!gotNumber)
        {
            if (s[i] == ' ')
            {
                continue;
            }
            if (s[i] == '+' && i != n-1 && s[i+1] >= '0' && s[i+1] <= '9')
            {
                isPositive = true;
                continue;
            }
            if (s[i] == '-' && i != n-1 && s[i+1] >= '0' && s[i+1] <= '9')
            {
                isPositive = false;
                continue;
            }
            if (s[i] >= 'A' || s[i] <= 'z')
            {
                return 0;
            }
        }
        
        while (s[i] >= '0' && s[i] <= '9' && i < n)
        {
            number = number * 10 + (int)s[i] - '0';
            if (number > MAX_NUMBER)
            {
                if (isPositive)
                {    
                    return MAX_NUMBER;
                }
                else {
                    return MIN_NUMBER;
                }
            }
            i++;
        }
        if (!isPositive)
        {
            number *= -1;
        }
        
        break;
    }
    return number;
}

int main(){
    string s;
    cin >> s;
    cout << myAtoi(s) << endl;
    return 0;
}