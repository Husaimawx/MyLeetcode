#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<string> > ans;

    vector<vector<string> > solveNQueens(int n) {
        vector<vector<int> > map;
        for (int i = 0; i < n; i++)
        {
            vector<int> row_map;
            for (int j = 0; j < n; j++)
            {
                row_map.push_back(0);
            }
            map.push_back(row_map);
        }
        

        vector<int> new_ans;
        digui(n, 0, new_ans, map);
    
        return ans;
    }

    void digui(int n, int pos, vector<int>& new_ans, vector<vector<int> >& map) {
        if (pos == n)
        {
            // 得到一个可行解
            vector<vector<char> > new_map;
            for (int i = 0; i < n; i++)
            {
                vector<char> row_new_map;
                for (int j = 0; j < n; j++)
                {
                    row_new_map.push_back('.');
                }
                new_map.push_back(row_new_map);
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    new_map[i][j] = '.';
                }
            }

            for (int i = 0; i < n; i++)
            {
                new_map[new_ans[i]][i] = 'Q';
            }

            vector<string> new_ans;
            for (int i = 0; i < n; i++)
            {
                string temp = "";
                for (int j = 0; j < n; j++)
                {
                    temp.push_back(new_map[i][j]);
                }
                new_ans.push_back(temp);
            }
            ans.push_back(new_ans);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (checkPos(i, pos, n, map))
            {
                // 回溯
                map[i][pos] = 1;
                new_ans.push_back(i);
                digui(n, pos + 1, new_ans, map);
                new_ans.pop_back();
                map[i][pos] = 0;
            }
            
        }
        
    }

    bool checkPos(int row, int col, int n, vector<vector<int> >& map) {
        // 行、列
        for (int i = 0; i < n; i++)
        {
            if (map[i][col] || map[row][i])
            {
                return false;
            }
        }

        // 四个方向的对角线

        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        {
            if (map[i][j])
            {
                return false;
            }
        }

        for (int i = row, j = col; i < n && j < n; i++, j++)
        {
            if (map[i][j])
            {
                return false;
            }
        }

        for (int i = row, j = col; i < n && j >= 0; i++, j--)
        {
            if (map[i][j])
            {
                return false;
            }
        }

        for (int i = row, j = col; i >= 0 && j < n; i--, j++)
        {
            if (map[i][j])
            {
                return false;
            }
        }
        return true;
    }
};


int main() {
    int n;
    cin >> n;

    Solution S;
    S.solveNQueens(n);
    return 0;
}