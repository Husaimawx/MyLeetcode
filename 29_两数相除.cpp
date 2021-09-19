#include <iostream>
#include <string.h>
using namespace std;

// 想到了用减法，但是只想到了一个一个减
// 可以用递归，通过比较大小一次减去最大倍数
// 60/8 = 4 + 2 + 1
// 难点在于考虑清楚各种边界
// INT_MIN = -2^32 INT_MAX = 2 ^ 32 - 1， 可以直接用
// 该用long的时候就用long，参数也要用， long长度是8位 



class Solution {
public:
    int getSign(int& dividend, int& divisor) {
        if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0))
        {
            return 1;
        }
        else {
            return -1;
        }
    }
    int divide(int dividend, int divisor) {
        if (divisor == 0)
        {
            return 0;
        }
        if (divisor == 1)
        {
            return dividend;
        }
        if (divisor == -1)
        {
            if (dividend == INT_MIN)
            {
                return INT_MAX;
            }
            return -dividend;
        }

        int sign = getSign(dividend, divisor);
        
        dividend = abs(dividend);
        divisor = abs(divisor);

        long ans = digui(dividend, divisor);
        if (sign > 0)
        {
            return ans;
        }
        else 
            return -ans;
    
    }
    long digui(long dividend, long divisor) {
        if (divisor == 1)
            return dividend;
        
        if (dividend < divisor)
            return 0;
        
        long cur = divisor;
        long pre = cur;
        int beishu = 1;
        int pre_beishu = 1;
        while (dividend >= cur + cur)
        {
            pre = cur;
            pre_beishu = beishu;
            beishu = beishu + beishu;
            cur = cur + cur;
            // cout << beishu << " " << cur << endl;
        }
        // cout << "beishu " << beishu <<  " pre " << pre << " next " << dividend - pre << endl;

        return pre_beishu + digui(dividend - pre, divisor);
    }
};

// dividend = 10, divisor = 3
int main() {
    int dividend, divisor;
    
    cin >> dividend >> divisor;

    // cout << dividend << " " << divisor << endl;
    Solution S;
    // cout << S.digui(7,3) << endl;
    cout << S.divide(dividend, divisor) << endl;
    return 0;
}