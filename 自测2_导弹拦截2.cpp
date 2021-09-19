#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;

int n,maxn,ans1,ans2,f[1000001],a[1000001];

int lowbit(int x) {return x&-x;}

void add(int x, int c) {
    for (int i = x; i <= maxn; i+=lowbit(i)) {
        f[i] = max(f[i], c);
    }
}

int query(int x){
	int res=0;
	for(int i=x;i>=1;i-=lowbit(i)) res=max(res,f[i]);//求以小于等于x的数为结尾的最长不上升子序列的长度的最大值 
	return res;
}

int main(){
	while(scanf("%d",&a[++n])!=EOF) maxn=max(maxn,a[n]);
	n--;//要-1，不然n就不是正确的n了 
	for(int i=n;i>=1;i--){//从后往前循环 
		int q=query(a[i])+1;//查询以小于等于x的数为开头的最长不上升子序列的长度的最大值
		add(a[i],q);//这个最大值+1就是以当前这个数开头的最长不上升子序列的长度，丢到树状数组里面去 
		ans1=max(ans1,q); 
	}
	printf("%d\n",ans1);
	memset(f,0,sizeof(f));//还是memset一下比较保险 
	for(int i=1;i<=n;i++){//从前往后循环 
		int q=query(a[i]-1)+1;//查询以小于（没有等于！！！）x的数为结尾的最长上升子序列的长度的最大值
		add(a[i],q);//这个最大值+1就是以当前这个数结尾的最长上升子序列的长度，丢到树状数组里面去 
		ans2=max(ans2,q);
	}
	printf("%d\n",ans2);
}