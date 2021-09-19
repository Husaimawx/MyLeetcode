#include <iostream>
#include <vector>
#include <string.h>
#include <sstream>
using namespace std;

// 首先想到了看每一行每一列，但是这样效率极低，应该优先量化关系：matrix[row][col] = matrix' [col][n−row−1]
// 根据这个关系式，首先可以发现两种解法：一是额外找一个矩阵，二是原地替换。原地替换的话需要对四个位置的点写出五个等式，用一个临时变量 temp 完成这四项的原地交换
// 还可以发现一个规律，顺时针旋转 = 先水平翻转，然后沿主对角线翻转 

class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        // cout << "row: " << row << " col: " << col << endl;
        for (int i = 0; i < row/2; i++)
        {
            for (int j = 0; j < col; j++)
            {
                // cout << matrix[i][j] <<  " " << matrix[row - i - 1][j] << endl;
                int temp = matrix[i][j];
                matrix[i][j] = matrix[row - i - 1][j];
                matrix[row - i - 1][j] = temp;
            }
        }

        for (int i = 0; i < row; i++)
        {
            for (int j = i + 1; j < col; j++)
            {
                // cout << matrix[i][j] <<  " " << matrix[j][i] << endl;
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
            
        }
        
        
    }

    void printMatrix(vector<vector<int> >& matrix) {
        cout << "row: " << matrix.size() << " col: " << matrix[0].size() << endl;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                cout << matrix[i][j] << " " ;
            }
            cout << endl;
        }
    }
};

// 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
// 输出：[[7,4,1],[8,5,2],[9,6,3]]

int main(){
    string input;
    cin >> input;

    input = input.substr(1,input.size() - 2);
    cout << input << endl;

    for (int i = 0; i < input.size() - 2; i++) {
        if (input[i] == ']' && input[i + 1] == ',' && input[i + 2] == '[') {
            input[i + 1] = ' ';
            i+=2;
        }
    }
    vector<vector<int> > matrix;
    
    stringstream out(input);
    string row;
    while (out >> row)
    {
        cout << row << endl;
        row = row.substr(1, row.size() - 2);
        for (int i = 0; i < row.size(); i++)
        {
            if (row[i] == ',')
            {
                row[i] = ' ';
            }
        }
        vector<int> r;
        stringstream outout(row);
        int num;
        while (outout >> num)
        {
            cout << num << endl;
            r.push_back(num);
        }
        matrix.push_back(r);
    }
    
    Solution S;
    S.printMatrix(matrix);
    S.rotate(matrix);
    S.printMatrix(matrix);

    return 0;
}