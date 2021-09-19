#include <iostream>
#include <vector>
using namespace std;

// 按身高降序，K升序排序，按照K值插入
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        if (a[0] == b[0]) return a[1] < b[1];
        else return a[0] > b[0];
    }
    vector<vector<int> > reconstructQueue(vector<vector<int> >& people) {
        int n = people.size();
        sort(people.begin(), people.end(), cmp);
        vector<vector<int> > ans;
        for (int i = 0; i < n; i++) {
            ans.insert(ans.begin() + people[i][1], people[i]);
        }
        return ans;
    }
};