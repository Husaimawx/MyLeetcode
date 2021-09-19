#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector <int> edge[110];
vector <int> w[110];
int n,q,dp[110][110],sum[110];

int dfs(int u,int source)
{
    int v;
    for(int i = 0; i < edge[u].size(); i++)
    {
        v = edge[u][i];
        if(v != source)
        {
            sum[u] += dfs(v,u);
        }
    }
    if(!sum[u])return 1;
    else return sum[u] + 1;
}

void solve(int u,int source)
{
    int v, cost;
    for(int i = 0; i < edge[u].size(); i++)
    {
        v = edge[u][i];
        cost = w[u][i];
        if(v != source)
        {
            solve(v,u);
            for(int j = q; j >= 1; j--)
            {
                for(int k = 0; k < j && k <= sum[u]; k++)
                {
                    dp[u][j] = max(dp[u][j], dp[u][j-k-1] + dp[v][k] + cost);
                }
            }
        }
    }
}
int main()
{
    cin >> n >> q;
    int x, y, z;
    for(int i = 1; i < n; i++)
    {
        cin >> x >> y >> z;
        edge[x].push_back(y);
        edge[y].push_back(x);
        w[x].push_back(z);
        w[y].push_back(z);
    }
    dfs(1,1);
    solve(1,1);
    int ans=0;
    cout << dp[1][q] << endl;
    return 0;
}