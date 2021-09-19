#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <climits>
using namespace std;

int n;
int a[100005];
int b[100005];
int map[100005];
int* dp;

// O(nlg(n)) 
// 将原来的dp数组的存储由 数值 换成 该序列中【上升子序列长度为i的上升子序列的最小末尾数值】

// 这其实就是一种几近贪心的思想：我们当前的上升子序列长度如果已经确定，那么如果这种长度的子序列的结尾元素越小，后面的元素就可以更方便地加入到这条我们臆测的、可作为结果、的上升子序列中。

int main () {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        map[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
    }
    
    dp = new int [n+1];
    memset(dp, INT_MAX, sizeof(n+1));
    //初始值要设为INF
    /*原因很简单，每遇到一个新的元素时，就跟已经记录的dp数组当前所记录的最长
    上升子序列的末尾元素相比较：如果小于此元素，那么就不断向前找，直到找到
    一个刚好比它大的元素，替换；反之如果大于，么填到末尾元素的下一个q，INF
            就是为了方便向后替换啊！*/ 
    
    int len = 0;//通过记录f数组的有效位数，求得个数 
	/*因为上文中所提到我们有可能要不断向前寻找，
	所以可以采用二分查找的策略，这便是将时间复杂
    度降成nlogn级别的关键因素。*/ 
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        int l = 0;
        int r = len;
        int mid;
        if (map[b[i]] > dp[len]) {
            len++;
            dp[len] = map[b[i]];
        }
        else {
            while (l < r)
            {
                mid = (l+r)/2;
                if(dp[mid] > map[b[i]]){
                    r = mid;
                }
                //如果仍然小于之前所记录的最小末尾，那么不断
                //向前寻找(因为是最长上升子序列，所以f数组必
                //然满足单调) 
			    else {
                    l = mid+1; 
                }
            }
            dp[l] = min(map[b[i]], dp[l]);
        }
    }
    printf("%d\n", len);
    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= n; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}