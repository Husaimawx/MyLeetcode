#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Pair{
    int pos;
    int h;
}Pl[205];

// 遍历起止行，对每一个矩形按高度求最大矩形面积
// 用单调栈，求left_most和right_most

class Solution {
public:
    int maximalRectangle(vector<vector<char> >& matrix) {
        int row = matrix.size();
        if (row == 0) return 0;
        int col = matrix[0].size();
        vector<vector<int> > heights(row, vector<int>(col, 0));
        int ans = 0;
        for (int j = 0; j < col; j++) {
            Pl[j].pos = j;
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (i == 0 && matrix[i][j] == '1') {
                   heights[i][j] = 1; 
                }
                else if (matrix[i][j] == '1') {
                   heights[i][j] = heights[i-1][j] + 1;
                }
                else {
                    heights[i][j] = 0;
                }
            }
            

            vector<int> rh = heights[i];
            for (int j = 0; j < col; j++) {
                Pl[j].h = rh[j];
            }
            stack<Pair> s;
            int left_most[205];
            int right_most[205];
            left_most[0] = 0;
            s.push(Pl[0]);
            for (int j = 1; j < col; j++) {
                left_most[j] = j;
                while(!s.empty() && s.top().h > rh[j]) {
                    
                    right_most[s.top().pos] = j;
                    left_most[j] = left_most[s.top().pos];
                    s.pop();
                }
                s.push(Pl[j]);
            }

            while (!s.empty()) {
                right_most[s.top().pos] = col;
                s.pop();
            }

            for (int j = 0; j < col; j++) {
                // cout << left_most[j] << " "<< right_most[j] << endl;
                ans = max(ans, (right_most[j] - left_most[j]) * rh[j]);
            }

        }
        
        
        
        return ans;
    }
};