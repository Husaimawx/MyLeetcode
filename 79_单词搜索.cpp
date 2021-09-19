#include <iostream>
#include <vector>
#include <string.h>
#include <sstream>
using namespace std;

class Solution {
public:
    int** visited;
    bool hasFound;
    bool exist(vector<vector<char> >& board, string word) {
        // for (int i = 0; i < board.size(); i++)
        // {
        //     for (int j = 0; j < board[0].size(); j++)
        //     {
        //         cout << board[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        int m = board.size();
        int n = board[0].size();
        visited = new int*[m];
        for (int i = 0; i < m; i++)
        {
            visited[i] = new int[n];
            memset(visited[i], 0, sizeof(int) * n);
        }
        hasFound = false;

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == word[0])
                {
                    for (int i = 0; i < m; i++)
                    {
                        memset(visited[i], 0, sizeof(int) * n);
                    }
                    visited[i][j] = 1;
                    dfs(board, word, 1, i, j);
                }
            }
        }
        return hasFound;
    }
    void dfs(vector<vector<char> >& board, string word, int step, int pos_r, int pos_c) {
        if (step == word.length())
        {
            cout << "get one" << endl;
            cout << pos_r << " " << pos_c << endl;
            hasFound = true;
            return;
        }
        if (hasFound)
        {
            return;
        }
        
        
        if (pos_r - 1 >= 0 && board[pos_r - 1][pos_c] == word[step] && visited[pos_r - 1][pos_c] == 0)
        {
            visited[pos_r - 1][pos_c] = 1;
            dfs(board, word, step + 1, pos_r - 1, pos_c);
            visited[pos_r - 1][pos_c] = 0;
        }
        if (pos_r + 1 < board.size() && board[pos_r + 1][pos_c] == word[step] && visited[pos_r + 1][pos_c] == 0)
        {
            visited[pos_r + 1][pos_c] = 1;
            dfs(board, word, step + 1, pos_r + 1, pos_c);
            visited[pos_r + 1][pos_c] = 0;
        }
        if (pos_c - 1 >= 0 && board[pos_r][pos_c-1] == word[step] && visited[pos_r][pos_c - 1] == 0)
        {
            visited[pos_r][pos_c - 1] = 1;
            dfs(board, word, step + 1, pos_r, pos_c - 1);
            visited[pos_r][pos_c - 1] = 0;
        }
        if (pos_c + 1 < board[0].size() && board[pos_r][pos_c+1] == word[step] && visited[pos_r][pos_c + 1] == 0)
        {
            visited[pos_r][pos_c + 1] = 1;
            dfs(board, word, step + 1, pos_r, pos_c + 1);
            visited[pos_r][pos_c + 1] = 0;
        }
        
        
    }
};

int main() {
    vector<vector<char> > board;
    string input;
    cin >> input;

    string word;
    cin >> word;
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
        vector<char> temp;
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
            temp.push_back(rowrow[1]);
        }
        board.push_back(temp);
    }
       
    Solution S;
    cout << S.exist(board, word) << endl;;

    return 0;
}