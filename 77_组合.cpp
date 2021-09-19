#include <iostream>
#include <vector>
using namespace std;

// 这是一个组合数问题，也就是对一个数选或者不选的问题。
class Solution {
public:
    vector<vector<int> > ans;
    vector<vector<int> > combine(int n, int k) {
        vector<int> cur;
        digui(n,k, 1, cur);
        return ans;
    }
    void digui(int n, int k, int pos, vector<int>& cur) {
        if (pos > n+1)
        {
            return;
        }
        
        if (cur.size() == k)
        {
            // cout << "get one " << endl;
            // for (int i = 0; i < cur.size(); i++)
            // {
            //     cout << cur[i] << " ";
            // }
            // cout << endl;
            ans.push_back(cur);
            return;
        }

        cur.push_back(pos);
        digui(n, k, pos + 1, cur);
        cur.pop_back();
        digui(n, k, pos + 1, cur);
    }
};
int main() {
    int n, k;
    cin >> n >> k;
    Solution S;
    S.combine(n, k);
    return 0;
}