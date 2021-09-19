#include <iostream> 
#include <string.h>
#include <vector>
using namespace std;

struct character
{
    int first;
    int last;
}characters[27];

// 先统计信息，然后排序，

class Solution {
public:
    static bool cmp(character a, character b){
        return a.first <= b.first;
    }
    vector<int> partitionLabels(string s) {
        int l = s.length();
        for (int i = 0; i < 27; i++)
        {
            characters[i].first = -1;
        }
        
        for (int i = 0; i < l; i++)
        {
            int c = s[i] - 'a' + 1;
            if (characters[c].first == -1)
            {
                characters[c].first = i;
            }
            characters[c].last = i;
        }
        
        vector<character> v_c;
        for (int i = 0; i < 27; i++)
        {
            if (characters[i].first != -1)
            {
                v_c.push_back(characters[i]);
            }
        }
        
        sort(v_c.begin(), v_c.end(), cmp);
        vector <int> ans;
        int pre_s = l;
        int pre_e = -1;
        for (int i = 0; i < v_c.size(); i++)
        {
            if (i > 0 && v_c[i].first >= pre_e)
            {
                cout << "get one peace" << " " << pre_s << " " << pre_e << endl;
                ans.push_back(pre_e - pre_s + 1);
                // pre -> v_c[i-1].last
                pre_s = v_c[i].first;
                pre_e = v_c[i].last;
            }
            else {
                pre_s = min(pre_s, v_c[i].first);
                pre_e = max(pre_e, v_c[i].last);
            }
            
        }
        cout << "get one peace" << " " << pre_s << " " << pre_e << endl;
        ans.push_back(pre_e - pre_s + 1);
        for (int i = 0; i < v_c.size(); i++)
        {
            cout << v_c[i].first << " " << v_c[i].last << endl;
        }
        
        return ans;
    }
};

int main () {
    string s = "ababcbacadefegdehijhklij";
    // cin >> s;

    Solution S;
    vector<int> ans = S.partitionLabels(s);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}