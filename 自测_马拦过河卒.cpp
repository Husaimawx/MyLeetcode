#include <iostream>
#include <string.h>
using namespace std;
long long n,m,hx,hy;
long long ** dp;
bool danger(long long a,long long b){
	if(a==hx&&b==hy)return true;
    else if(a==hx-1&&b==hy+2)return true;
    else if(a==hx-1&&b==hy-2)return true;
    else if(a==hx-2&&b==hy+1)return true;
    else if(a==hx-2&&b==hy-1)return true;
    else if(a==hx+1&&b==hy+2)return true;
    else if(a==hx+1&&b==hy-2)return true;
    else if(a==hx+2&&b==hy-1)return true;
    else if(a==hx+2&&b==hy+1)return true;
    else return false;
}

long long getAns() {
    if (!danger(0,0)) dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
        if (!danger(i, 0))dp[i][0] = dp[i-1][0];
    for (int i = 1; i <= m; i++)
        if (!danger(0, i))dp[0][i] = dp[0][i-1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!danger(i,j)) {
                if (!danger(i-1,j)) dp[i][j] += dp[i-1][j];
                if (!danger(i,j-1)) dp[i][j] += dp[i][j-1];
            }
        }
    }
    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= m; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return dp[n][m];
}
int main(){
	cin>>n>>m>>hx>>hy;
	dp = new long long * [n+1];
    for (int i = 0; i <= n; i++) {
        dp[i] = new long long[m+1];
        memset(dp[i], 0, sizeof(long long) * (m+1));
    }
	cout << getAns() << endl;
	return 0;	
}
