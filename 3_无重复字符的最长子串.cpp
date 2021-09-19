#include <iostream>
#include <string>
using namespace std;

// 滑动窗口

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int array[128];
        int ans = 0;
        int max_length = 0;

        for (int i = 0; i < 128; i++)
            array[i] = -1;
        
        
        for (int i = 0; i < s.size(); i++)
        {
            // cout << "begin with " << s[i] << endl;
            while (array[(int)s[i]] == -1)
            {
                //cout << "skip " << s[i] << endl;
                array[(int)s[i]] = i;
                i++;
                max_length ++ ;
                if (i == s.size()) break;
            }
            if (i == s.size()) {
                if(ans < max_length)
                    ans = max_length;
                break;
            }
            if (array[(int)s[i]] != -1)
            {
                if(ans < max_length)
                    ans = max_length;
                
                i = array[(int)s[i]];
                memset(array, -1, sizeof(array));
                max_length = 0;
            }           
            
        }
        return ans;
    }
};

int main(){
    string stdin;
    //cin >> stdin;
    stdin = " ";
    //stdin = stdin.substr(1,stdin.size()-2);
    cout << " stdin " << stdin << endl;
    Solution s;
    cout << s.lengthOfLongestSubstring(stdin) << endl;


    return 0;
}

/*
    8ms 范例

    int lengthOfLongestSubstring(string s) {
        int a[256] = {0}, res = 0, left = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            if(a[s[i]] == 0 || a[s[i]] < left)
            {
                res = std::max(res, i - left + 1);
            }
            else
            {
                left = a[s[i]];
            }
            a[s[i]] = i + 1;
        }
        return res;
    }

*/