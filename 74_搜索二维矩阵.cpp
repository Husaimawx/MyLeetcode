#include <iostream>
#include <vector>
#include <string.h>
#include <sstream>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        if (matrix.size() < 1 || matrix[0].size() < 1)
        {
            return false;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        
        int pos_i = m - 1;
        int pos_j = 0;
        while (matrix[pos_i][pos_j] != target)
        {
            // cout << "pos_i " << pos_i << " pos_j " << pos_j << endl;
            
            if (matrix[pos_i][pos_j] < target)
            {
                pos_j ++;
            }
            else if (matrix[pos_i][pos_j] > target)
            {
                pos_i --;
            }
            else {
                return true;
            }
            if (pos_i < 0 || pos_i > m - 1 || pos_j < 0 || pos_j > n - 1)
            {
                return false;
            }
        }

        return true;
    }
};

int main() {
    vector<vector<int> > matrix;
    string input;
    cin >> input;
    int target;
    cin >> target;
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
    cout << S.searchMatrix(matrix, target) << endl;;

    return 0;
}