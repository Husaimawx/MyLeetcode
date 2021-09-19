#include <iostream>
#include <vector>
#include <string.h>
#include <sstream>
using namespace std;

class Solution {
public:
    int* row;
    int* col;
    
    // 用两个数组记录一遍这一行或列是否有0
    void setZeroes(vector<vector<int> >& matrix) {
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
        
        int m = matrix.size();
        int n = matrix[0].size();
        row = new int[m];
        col = new int[n];
        memset(row, 0, sizeof(int) * m);
        memset(col, 0, sizeof(int) * n);

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    row[i] = 1;
                    col[j] = 1;
                }
                
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (row[i] == 1 || col[j] == 1)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        
        

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

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
    S.setZeroes(matrix);

    return 0;
}