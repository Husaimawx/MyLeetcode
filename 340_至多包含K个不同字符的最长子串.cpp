#include <iostream>
#include <string.h>
#include <map>
#include <unordered_map>
using namespace std;

// 滑动窗口，unordered_map记录当前窗口中的字符数
// 字符种类为map.size()，数量为0时erase

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (k == 0) {
            return 0;
        }
        unordered_map<char, int> maps;
        int n = s.size();
        int ans = 0;
        int l = 0;
        for (int r = 0; r < n; r++)
        {
            maps[s[r]] ++;
            while (maps.size() > k)
            {
                maps[s[l]] --;
                if (maps[s[l]] == 0)
                {
                    maps.erase(s[l]);
                }
                l++;
            }
            ans = max(ans, r - l + 1);
            
        }
        
        return ans;
    }
};

int main () {
    string s;
    int k;
    cin >> s >> k;

    Solution S;
    cout << S.lengthOfLongestSubstringKDistinct(s, k) << endl;
    return 0;
}