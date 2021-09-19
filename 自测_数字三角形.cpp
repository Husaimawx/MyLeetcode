#include <iostream>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int getAns(int r, int** n){
    if (r == 1) {
        return n[0][0];
    }
    int** dp = new int* [r+1];
    for (int i = 0; i <= r; i++){
        dp[i] = new int[r+1];
        memset(dp[i], 0, sizeof(int) * (r+1));
    }
    

    for (int i = 1; i <= r; i++){
        for (int j = 1; j <= i; j++) {
            dp[i][j] = n[i-1][j-1];
            if (j == 1) {
                dp[i][j] += dp[i-1][j];
            }
            else if (j == i){
                dp[i][j] += dp[i-1][j-1];
            }
            else {
                dp[i][j] += max(dp[i-1][j], dp[i-1][j-1]);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= r; i++) {
        ans = max(ans, dp[r][i]);
    }
    return ans;
}   


int main () {
    int r;
    cin >> r;
    int ** n = new int *[r];
    for (int i = 0; i < r; i++) {
        n[i] = new int [r];
        memset(n[i], 0, sizeof(int)*r);
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j <= i; j++) {
            string num;
            cin >> n[i][j];
        }
    }

    // for (int i = 0; i < r; i ++) {
    //     for (int j = 0; j < r; j ++) {
    //         cout << n[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << getAns(r, n) << endl;

    return 0;
}