#include <iostream>
#include <string.h>
#include <set>
using namespace std;

// 滑动窗口 可以用双指针，也可以用双端队列 Deque
// 分三种情况来移动窗口：（这里令当前窗口的左右边界分别为l，r，窗口的大小为 winSize = r - l + 1）
//    1) 当winSize < t.size()  r++;  也就是窗口右边界向右移动
//    2) 当winSize == t.size() :
// 	    当窗口中的字符已经符合要求了，直接返回return，已经找到了
// 	    否则r++，窗口右边界向右移动
//    3) 当winSize > t.size()
// 	    当窗口中的字符已经符合要求了，l++，窗口左边界向右移动
// 	    否则r++，窗口右边界向右移动
// 还需要缩小窗口

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size())
        {
            return "";
        }
        
        int t_list[128];
        bool t_has[128];
        memset(t_list, 0, sizeof(int) * 128);
        memset(t_has, 0, sizeof(bool) * 128);
        for (int i = 0; i < t.size(); i++)
        {
            t_list[t[i]] ++;
            t_has[t[i]] = 1;
        }

        string ans;
        int cnt = 0;
        int l = 0;
        int min_l = 0;
        int min_size = s.size() + 1;

        for (int i = 0; i < s.length(); i++)
        {
            if (t_has[s[i]])
            {
                if (--t_list[s[i]] >= 0)
                {
                    cnt ++;
                }
                
                
                while (cnt == t.size())
                {
                    
                    if (i - l + 1 < min_size)
                    {
                        min_l = l;
                        min_size = i -l + 1;
                    }
                    if (t_has[s[l]] && ++t_list[s[l]] > 0)
                    {
                        -- cnt;
                    }
                    l++;
                }
            }
        }
        if (min_size > s.size())
        {
            return "";
        }
        
        return s.substr(min_l, min_size);
    }
};

int main () {
    string s = "ab";
    string t = "aaab";
    Solution S;
    cout << S.minWindow(s,t) << endl;

    return 0;
}