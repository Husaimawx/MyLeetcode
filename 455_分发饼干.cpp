#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(),s.end());
        int i = 0;
        int j = 0;
        int m = g.size();
        int n = s.size();
        int cnt = 0;
        while(i < m && j < n) {
            // cout << s[j] << " " << g[i] << endl;
            if (s[j] >= g[i]) {
                cnt ++;
                i++;
                j++;
            }
            else {
                j++;
            }
        }
        return cnt;
    }
};