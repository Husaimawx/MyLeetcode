#include <iostream>
#include <string>
using namespace std;

// low 左括号最少能有多少个，high 左括号最多能有多少个
class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;
        int high = 0;
        int n = s.size();
        for (int i = 0 ; i < n; i++) {
            if (s[i] == '(') {
                low ++;
                high ++;
            }
            else if (s[i] == ')') {
                if (low > 0) low --;
                high --;
            }
            else if (s[i] == '*') {
                if (low > 0) low --;
                high ++;
            }
            if (high < 0) return false;
        }
        return low == 0;
    }
};