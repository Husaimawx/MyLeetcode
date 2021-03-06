#include <iostream>
#include <string.h>
using namespace std;


class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t rev = 0;
        for (int i = 0; i < 32 && n > 0; ++i) {
            rev |= (n & 1) << (31 - i);
            cout << n << endl;
            n >>= 1;
        }
        return rev;
    }
};

int main () {
    uint32_t n;
    cin >> n;
    cout << n << endl;
    Solution S;
    cout << S.reverseBits(n) << endl;
    return 0;
}