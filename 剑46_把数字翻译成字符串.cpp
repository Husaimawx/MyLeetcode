#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

// dp[i]

class Solution {
public:
    int translateNum(int num) {
        string str;
        stringstream out;
        out << num;
        out >> str;
        int n = str.size();
        
        vector<int> dp(n + 1, 0);

        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i-1];
            if (i > 1 && str[i-2] != '0' && (str[i-2] - '0') * 10 + (str[i-1] - '0') < 26) {
                // cout << (str[i-2] - '0') * 10 + (str[i-1] - '0')  << endl;
                dp[i] += dp[i-2];
            }
        }
        // for (int i = 0 ; i <= n; i++) {
        //     cout << dp[i] << " ";
        // }
        // cout << endl;
        return dp[n];
    }
};