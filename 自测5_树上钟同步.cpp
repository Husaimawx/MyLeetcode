#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <limits.h>
using namespace std;

const int maxn = 2505;
int n;
vector<int> mmap[maxn];
vector<int> point(maxn);
int dfs(int i,vector<int>&visited){
    if (visited[i]) return 0;
    visited[i] = 1;
    int res = point[i];
    for(int j=0;j<mmap[i].size();j++){
        res += (12 - dfs(mmap[i][j],visited));
    }
    return res%12;
};

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&point[i]);
    }
    for(int i=0;i<n-1;i++){
        int n1,n2;
        scanf("%d %d",&n1,&n2);
        mmap[n1-1].push_back(n2-1);
        mmap[n2-1].push_back(n1-1);
    }
    for(int i=0;i<n;i++){
        vector<int> visited(2500,0);
        int temp = dfs(i,visited);
        if(temp<=1)
            printf("%d ",i+1);
    }
}