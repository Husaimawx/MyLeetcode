#include <iostream>
#include <string.h>
#include <vector>
#include <sstream>
using namespace std;

// 又是一道dp，刚开始还想着是不是不需要dp，但是思考了半天也没想出来其他方法，反而专注用dp之后很快写出来了。
// 转移方程也是很明显的：dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i-1][j-1]; 
// 应该说是最简单的dp了吧，一遍过。

class Solution {
public:

    int minimumTotal(vector<vector<int> >& triangle) {
        int m = triangle.size();
        int** dp;
        dp = new int* [m + 1];
        for (int i = 0; i < m+1; i++)
        {
            dp[i] = new int [i + 1];
            memset(dp[i], 0, sizeof(int) * (i+1));
        }
        
        for (int i = 1; i < m + 1; i++)
        {
            for (int j = 1; j < i + 1; j++)
            {
                if (i == 1 && j == 1)
                {
                    dp[i][j] = triangle[0][0];
                    continue;
                }
                
                if (j == 1)
                {
                    dp[i][j] = dp[i - 1][j] + triangle[i-1][j-1];
                }
                else if (i == j)
                {
                    dp[i][j] = dp[i - 1][j - 1] + triangle[i-1][j-1];
                }
                else {
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i-1][j-1]; 
                }
            }
        }
        

        // for (int i = 0; i < triangle.size(); i++)
        // {
        //     for (int j = 0; j < triangle[i].size(); j++)
        //     {
        //         cout << triangle[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // for (int i = 0; i < m + 1; i++)
        // {
        //     for (int j = 0; j < i + 1; j++)
        //     {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        
        int min_sum = INT_MAX;
        for (int i = 1; i < m + 1; i++)
        {
            if (dp[m][i] < min_sum)
            {
                min_sum = dp[m][i];
            }
            
        }
        return min_sum;
    }
};
// [[2],[3,4],[6,5,7],[4,1,8,3]]
int main() {
    vector<vector<int> > triangle;

    string input;
    cin >> input;
    input = input.substr(1, input.length() - 2);
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == ']' && input[i+1] == ',' && input[i+2] == '[' )
        {
            input[i] = ']';
            input[i+1] = ' ';
            input[i+2] = '[';
        }
    }
    istringstream output(input);
    string temp;
    while (output >> temp)
    {
        cout << temp << endl;
        temp = temp.substr(1, temp.length() - 2);
        for (int i = 0; i < temp.length(); i++)
        {
            if (temp[i] == ',')
            {
                temp[i] = ' ';
            }
        }
        istringstream tempout(temp);
        vector <int> newV;
        string temptemp;
        while (tempout >> temptemp)
        {
            newV.push_back(atoi(temptemp.c_str()));
        }
        triangle.push_back(newV);
        
    }
    

    Solution S;
    cout << S.minimumTotal(triangle) << endl;;
    return 0;
}