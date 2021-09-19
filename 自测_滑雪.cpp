#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;

int r, c;
int ** matrix;
int ** dp;

int getDP(int x, int y) {
    if (dp[x][y] != 0) return dp[x][y];
    if (x-1 >= 0 && matrix[x-1][y] > matrix[x][y]) {
        dp[x][y] = max(dp[x][y], getDP(x-1, y) + 1);
    }
    if (x+1 < r && matrix[x+1][y] > matrix[x][y]) {
        dp[x][y] = max(dp[x][y], getDP(x+1, y) + 1);
    }
    if (y-1 >= 0 && matrix[x][y-1] > matrix[x][y]) {
        dp[x][y] = max(dp[x][y], getDP(x, y-1) + 1);
    }
    if (y+1 < c && matrix[x][y+1] > matrix[x][y]) {
        dp[x][y] = max(dp[x][y], getDP(x, y+1) + 1);
    } 
    return dp[x][y];
}

int getAns() {
    int ans = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            dp[i][j] = getDP(i,j);   
            ans = max(ans, dp[i][j]);
        }
    }

    // for (int i = 0; i < r; i++) {
    //     for (int j = 0; j < c; j++) {
    //         printf("%d ", dp[i][j]);
    //     }
    //     printf("\n");
    // }
    return ans + 1;
}

int main() {
    scanf("%d %d", &r, &c);

    matrix = new int*[r];
    dp = new int*[r];
    for (int i = 0; i < r; i ++) {
        matrix[i] = new int[c];
        dp[i] = new int[c];
        memset(dp[i], 0, sizeof(int) * c);
    }
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("%d\n", getAns());
    return 0;
}