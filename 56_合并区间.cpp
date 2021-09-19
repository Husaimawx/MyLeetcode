#include <iostream>
#include <vector>
#include <string.h>
#include <sstream>
using namespace std;
// for (int i = 0; i < intervals.size(); i++)
// {
//     for (int j = 0; j < intervals[0].size(); j++)
//     {
//         cout << intervals[i][j] << " ";
//     }
//     cout << endl;
// }
// [[1,3],[2,6],[8,10],[15,18]]
// [[1,3],[8,10],[2,6],[15,18]]
// [[1,3],[8,10],[2,18],[15,18]]
class Solution {
public:
    vector<vector<int> > merge(vector<vector<int> >& intervals) {
        if (intervals.size() <= 1)
        {
            return intervals;
        }

        sort(intervals.begin(), intervals.end());
        
        vector<vector<int> > ans;
        
        for (int i = 0; i < intervals.size(); i++)
        {
            // merge i and i+1
            if (i < intervals.size() - 1)
            {
                if (intervals[i][1] < intervals[i+1][0])
                {
                    ans.push_back(intervals[i]);
                }
                else {
                    intervals[i+1] = mergeTwoInterval(intervals[i], intervals[i+1]);
                }
            }
            else {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }

    vector<int> mergeTwoInterval(vector<int> first, vector<int> second) {
        vector<int> ans;
        if (first[1] < second[0])
        {
            return ans;
        }
        else {
            ans.push_back(min(first[0], second[0]));
            ans.push_back(max(first[1], second[1]));
            return ans;
        }
    }

};

int main () {
    vector<vector<int> > intervals;
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
        intervals.push_back(temp);
    }


    Solution S;
    vector<vector<int> > ans = S.merge(intervals);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }
    
    return 0;
}