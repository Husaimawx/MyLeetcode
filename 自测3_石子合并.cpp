#include<iostream>  
#include<cstdio>  
#include<cmath>  
using namespace std;   
int n,minl,maxl,f1[300][300],f2[300][300],num[300];  
int s[300];  

inline int d(int i,int j) { 
    return s[j]-s[i-1];
}  

//转移方程：f[i][j] = max(f[i][k]+f[k+1][j]+d[i][j];

int main()  
{   
    scanf("%d",&n);  
    for(int i=1;i<=n+n;i++)  // 因为是一个环，所以需要开到两倍再枚举分界线，最后肯定是最大的 
    {  
        scanf("%d",&num[i]);  
        num[i+n] = num[i];  
        s[i] = s[i-1] + num[i];  
    }  
    for(int len = 1; len < n; len++)  // 枚举j-i
    {  
        for(int i = 1,j = i + len; (j < n + n) && (i < n + n); i++, j = i + len)  
        {  
            f2[i][j] = INT_MAX;  
            for(int k = i; k < j; k++)  
            {  
                f1[i][j] = max(f1[i][j], f1[i][k]+f1[k+1][j]+d(i,j));   
                f2[i][j] = min(f2[i][j], f2[i][k]+f2[k+1][j]+d(i,j));  
            }  
        }  
    }  
    minl = INT_MAX;  
    for(int i=1;i<=n;i++)  
    {  
        maxl=max(maxl,f1[i][i+n-1]);  
        minl=min(minl,f2[i][i+n-1]);  
    }  
    printf("%d\n%d",minl,maxl);  
    return 0;  
}


const int INF=0x7fffffff;
int n,m,ans1,ans2;
int A[205],f1[205][205],f2[205][205];
int dfs1(int L,int R){                //求出最小得分 
    if(f1[L][R])return f1[L][R];    //已保存的状态不必搜索 
    if(L==R)    return f1[L][R]=0;    //L==R时返回0 
    int res=INF;                    //初始值赋为最大值以求最小值 
    for(int k=L;k<R;k++)            //枚举K搜索 
        res=min(res,dfs1(L,k)+dfs1(k+1,R)+A[R]-A[L-1]);
    return f1[L][R]=res;            //记录状态 
}
int dfs2(int L,int R){                //求出最大得分 
    if(f2[L][R])return f2[L][R];
    if(L==R)    return f2[L][R]=0;    //若初始值为0可省略该句 
    int res=0;                        //初始值设为0 
    for(int k=L;k<R;k++)
        res=max(res,dfs2(L,k)+dfs2(k+1,R)+A[R]-A[L-1]);
    return f2[L][R]=res;
}
int main(){
    std::ios::sync_with_stdio(false);//取消cin与stdin同步,加速读入 
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>A[i];
        A[i+n]=A[i];                //因为是环所以保存为长度为2n的链以保证不会漏解 
    }
    for(int i=1;i<=2*n;i++)            //求出前缀和 
        A[i]+=A[i-1];
    dfs1(1,2*n);dfs2(1,2*n);        //搜索出1-2n的最大得分与最小得分 
    ans1=INF;    ans2=0;
    for(int i=1;i<=n;i++){
        ans1=min(f1[i][n+i-1],ans1);//选出答案 
        ans2=max(f2[i][n+i-1],ans2);
    }
    cout<<ans1<<"\n"<<ans2;
    return 0;
}