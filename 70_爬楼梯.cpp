#include <iostream>
using namespace std;


class Solution {
public:
    int * dp;
    int climbStairs(int n) {
        if (n == 1) return 1;
        dp = new int[n];
        dp[0] = 1;
        dp[1] = 2; 
        for (int i = 2; i < n ; i ++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n-1];
    }
};