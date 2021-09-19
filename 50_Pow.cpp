#include <iostream>
using namespace std;

// 计算a的n次方
// 如果n是偶数（不为0），那么就先计算a的n/2次方，然后平方；
// 如果n是奇数，那么就先计算a的n-1次方，再乘上a；
// 递归出口是a的0次方为1。


class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if (x == 1.0)
        {
            return 1.0;
        }
        
        if (N > 0)
        {
            return digui(x, N);
        }
        else {
            return 1/digui(x,-N);
        }
    }
    double digui(double x, long long n){
        if (n == 0)
        {
            return 1.0;
        }

        if (n % 2 == 0)
        {
            double new_ans = digui(x, n/2);
            return new_ans * new_ans;
        }
        else {
            return digui(x, n - 1) * x;
        }
    }
};

int main() {
    double x;
    int n;
    cin >> x >> n;
    Solution S;
    cout << S.myPow(x, n)<< endl;;
    return 0;
}