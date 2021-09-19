#include <iostream>
#include <vector>
#include <string.h>
#include <sstream>
using namespace std;

class Solution {
public:
    int** dp;
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        dp = new int* [m];
        for (int i = 0; i < m; i++)
        {
            dp[i] = new int [n];
            memset(dp[i], 0, sizeof(int) * n);
        }
        
        if (obstacleGrid[0][0])
        {
            dp[0][0] = 0;
        }
        else {
            dp[0][0] = 1;
        }

        for (int i = 1; i < m; i++)
        {
            if (obstacleGrid[i][0])
            {
                dp[i][0] = 0;
            }
            else {
                dp[i][0] = dp[i-1][0];
            }
        }
        

        for (int i = 1; i < n; i++)
        {
            if (obstacleGrid[0][i])
            {
                dp[0][i] = 0;
            }
            else {
                dp[0][i] = dp[0][i-1];
            }
        }
        
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (obstacleGrid[i][j])
                {
                    dp[i][j] = 0;
                }
                else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        // for (int i = 0; i < obstacleGrid.size(); i++)
        // {
        //     for (int j = 0; j < obstacleGrid[0].size(); j++)
        //     {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return dp[m - 1][n - 1];
    }
};


int main(){
    vector<vector<int> > obstacleGrid;
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
        obstacleGrid.push_back(temp);
    }
       
    Solution S;
    cout << S.uniquePathsWithObstacles(obstacleGrid) << endl;;

    return 0;
}