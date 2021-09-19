#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// 分治

class Solution {
public:
    unordered_map<int,vector<int> > map;
    vector<int> beautifulArray(int n) {
        return fenzhi(n);
    }
    vector<int> fenzhi(int n) {
        vector<int> ans;
        if (map.find(n) != map.end()) {
            return map[n];
        }
        if (n == 1) {
            ans.push_back(1);
            return ans;
        }
        else {
            vector<int> left = fenzhi((n + 1) / 2);
            vector<int> right = fenzhi(n / 2);
            for (int i = 0; i < left.size(); i++) {
                ans.push_back(2 * left[i] - 1);
            }
            for (int i = 0; i < right.size(); i++) {
                ans.push_back(2 * right[i]);
            }
        }
        map[n] = ans;
        return ans;
    }
};