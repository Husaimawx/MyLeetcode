#include <iostream>
#include <vector>
#include <string.h>
#include <sstream>
using namespace std;

// 贪心法，冲突时优先保留结尾小的
class Solution {
public:
    static bool cmp (vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int> >& intervals) {
        // for (int i = 0; i < intervals.size(); i++)
        // {
        //     for (int j = 0; j < intervals[i].size(); j++)
        //     {
        //         cout << intervals[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        if (intervals.empty())
        {
            return 0;
        }
        sort(intervals.begin(), intervals.end(), cmp);
        int far = INT_MIN;
        int cnt = 0;
        for (int i = 0; i < intervals.size(); i++)
        {
            if (intervals[i][0] < far)
            {
                cnt ++;
            }
            else {
                far = intervals[i][1];
            }
        }
        
        return cnt;
    }
};

int main () {
    vector<vector<int> > intervals;
    vector<int>temp;
    temp.push_back(1);
    temp.push_back(2);
    intervals.push_back(temp);
    temp.clear();
    temp.push_back(2);
    temp.push_back(3);
    intervals.push_back(temp);
    temp.clear();
    temp.push_back(3);
    temp.push_back(4);
    intervals.push_back(temp);
    temp.clear();
    temp.push_back(1);
    temp.push_back(3);
    intervals.push_back(temp);

    Solution S;
    cout << S.eraseOverlapIntervals(intervals) << endl;;

    return 0;
}