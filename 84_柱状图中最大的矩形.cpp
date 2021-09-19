#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 单调栈，记录left_most和right_most数组

struct p {
    int pos;
    int height;
}pl[100005];
class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 1) return heights[0];

        for (int i = 0; i < n; i++) {
            pl[i].pos = i;
            pl[i].height = heights[i];
        }

        stack<p> s;
        s.push(pl[0]);
        int right_most[100005];
        int left_most [100005];

        left_most[0] = 0;
        
        for (int i = 1; i < n; i++) {
            left_most[i] = i;
            while (!s.empty() && s.top().height > heights[i]){
                right_most[s.top().pos] = i;
                left_most[i] = left_most[s.top().pos];
                s.pop();
            }
            s.push(pl[i]);
        }
        while (!s.empty()) {
            right_most[s.top().pos] = n;
            s.pop();
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, heights[i] * (right_most[i] - left_most[i]));
        }
        return ans;
    }
};