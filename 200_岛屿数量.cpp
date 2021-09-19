#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int visit[305][305];
    int ans;
    int m,n;
    const int d[5] = {1, 0, -1, 0, 1};
    int numIslands(vector<vector<char> >& grid) {
        m = grid.size();
        n = grid[0].size();
        ans = 0;
        

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                visit[i][j] = 0;
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visit[i][j] == 0 && grid[i][j] == '1') {
                    ans ++;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }
    
    void dfs(vector<vector<char> >& grid, int row, int col) {
        
        for (int i = 0; i < 4; i++) {
            int newr = row + d[i];
            int newc = col + d[i+1];
            if (newr >=0 && newr < m && newc >= 0 && newc < n &&visit[newr][newc] == 0 && grid[newr][newc] == '1') {
                visit[newr][newc] = 1;
                dfs(grid, newr, newc);
            }
        }
    }
};