#include <iostream>
#include <vector>
using namespace std;

// 并查集

class Solution {
public:
    vector<int> parent;
    void init(int size) {
        for (int i = 0; i < size; i++) {
            parent.push_back(i);
        }
    }
    int find(int x) {
        return parent[x] == x ? x : find(parent[x]); 
    }
    void join(int x1, int x2) {
        int p1 = find(x1);
        int p2 = find(x2);
        if (p1 != p2) {
            parent[p1] = p2;
        }
    }
    static bool bmp(const vector<int>& a, const vector<int>& b) {
        if (a[2] > b[2]) {
            return false;
        }
        return true;
    }
    int minimumCost(int n, vector<vector<int> >& connections) {
        init(n);
        for (int i = 0; i < n; i++) {
            cout << parent[i] << endl;
        }
        sort(connections.begin(), connections.end(), bmp);    
        // for (int i = 0; i < connections.size(); i++) {
        //     cout << connections[i][0] << " " << connections[i][1] << " " << connections[i][2] << endl;
        // }
        int ans = 0;
        int len = 0;
        for (int i = 0; i < connections.size(); i++) {
            int a = connections[i][0];
            int b = connections[i][1];
            // cout << find(a-1) << " " << find(b-1) << endl;
            if (find(a-1) != find(b-1)){
                join(a-1, b-1);
                ans += connections[i][2];
                len ++;
            }
        }
        if (len < n - 1) {
            return -1;
        }
        return ans;
    }
};