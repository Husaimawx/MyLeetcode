#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPre(string& a, string& b) {
        if(b.size() - a.size() != 1){
            return false;
        }
        int pos = 0;
        for (int i = 0; i < b.size(); i++) {
            if (b[i] == a[pos]) pos ++;
        }
        if (pos == a.size()) return true;
        return false;
    }
    static bool cmp(const string& a, const string& b) {
        return a.size() < b.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(),cmp);
        int n = words.size();
        int ans = 1;
        vector<int> dp(n+1, 1);
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                if (isPre(words[j-1], words[i-1])) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};