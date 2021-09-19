#include <iostream>
#include <vector>
using namespace std;

// 按右端点排序，每次都打右端点
class Solution {
public:
    static bool cmp (const vector<int> & a, const vector<int> & b) {
        return a[1] < b[1];
    }
    int findMinArrowShots(vector<vector<int> >& points) {
        sort(points.begin(), points.end(), cmp);
        // for (int i = 0; i < points.size(); i++) {
        //     cout << points[i][0] << " " << points[i][1] << endl;
        // }
        if (points.size() == 0) return 0;
        if (points.size() == 1) return 1;
        long long cnt = 0;
        long long pre = INT_MIN;
        for (int i = 0; i < points.size(); i++) {
            if (points[i][0] > pre) {
                cnt ++;
                pre = points[i][1];
            }
        }
        return cnt;
    }
};