#include <sstream>
#include <string>
using namespace std;


class Solution {
public:
    int reverse(int x) {
        bool flag = false;
        if (x < 0) {
            flag = true;
            x= -x;
        }
        stringstream s;
        s << x;
        string str = s.str();
        std::reverse(str.begin(), str.end());
        // cout << str;
        int ans = atoi(str.c_str());

        if (flag){
            if (ans > (2 << 31)) return 0;
            return -ans;
        }
        else {
            if (ans > (2 << 31 -1)) return 0;
            return ans;
        }
    }
};