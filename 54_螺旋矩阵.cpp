#include <iostream>
#include <vector>
#include <string.h>
#include <sstream>
using namespace std;

class Solution {
public:
    // 四种状态
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> ans;
        int state = 1;
        int m = matrix.size();
        int n = matrix[0].size();
        int pos_m = 0;
        int pos_n = 0;
        while (m && n)
        {
            if (state == 1)
            {
                for (int i = 0; i < n; i++)
                {
                    ans.push_back(matrix[pos_m][pos_n]);
                    cout << "push " << pos_m << " " << pos_n << endl;
                    pos_n++;
                }
                pos_n--;
                pos_m++;
                state = 2;
                m--;
            }
            else if (state == 2)
            {
                for (int i = 0; i < m; i++)
                {
                    ans.push_back(matrix[pos_m][pos_n]);
                    cout << "push " << pos_m << " " << pos_n << endl;
                    pos_m ++;
                }
                pos_m--;
                pos_n--;
                state = 3;
                n--;
            }
            else if (state == 3)
            {
                for (int i = 0; i < n; i++)
                {
                    ans.push_back(matrix[pos_m][pos_n]);
                    cout << "push " << pos_m << " " << pos_n << endl;
                    pos_n--;
                }
                pos_n++;
                pos_m--;
                state = 4;
                m--;
            }
            else if (state == 4)
            {
                for (int i = 0; i < m; i++)
                {
                    ans.push_back(matrix[pos_m][pos_n]);
                    cout << "push " << pos_m << " " << pos_n << endl;
                    pos_m--;
                }
                pos_m++;
                pos_n++;
                state = 1;
                n--;
            }
        }
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i];
        }
        return ans;
        
    }
};
// 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
// 输出：[1,2,3,6,9,8,7,4,5]
int main() {
    vector<vector<int> > matrix;
    string input;
    cin >> input;
    input = input.substr(1,input.length() - 2);
    for (int i = 0; i < input.length() - 2; i++)
    {
        if (input[i] == ']' && input[i+1] == ',' && input[i+2] == '[')
        {
            input[i] = ']';
            input[i+1] = ' ';
            input[i+2] = '[';
        }
    }
    
    
    istringstream output(input);
    string row;
    while (output >> row)
    {
        vector<int> temp;
        row = row.substr(1, row.length() - 2);
        for (int i = 0; i < row.length(); i++)
        {
            if (row[i] == ',')
            {
                row[i] = ' ';
            }
        }
        istringstream outoutput(row);
        string rowrow;
        while (outoutput >> rowrow)
        {
            int num = atoi(rowrow.c_str());
            temp.push_back(num);
        }
        matrix.push_back(temp);
    }
       
    Solution S;
    S.spiralOrder(matrix);

    return 0;
}