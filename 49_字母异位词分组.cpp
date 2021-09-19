#include <iostream> 
#include <vector>
#include <string.h>
#include <sstream>
#include <map>
using namespace std;

// 输入: strs = ["eat","tea","tan","ate","nat","bat"]
// 输出: [["bat"],["nat","tan"],["ate","eat","tea"]]

// 用一个数据结构：map<string, vector<string>>

class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        vector<vector<string> > ans;
        map<string, vector<string> > v_map;
        for (int i = 0; i < strs.size(); i++)
        {
            string key = getVal(strs[i]);
            if (v_map[key].size() == 0)
            {
                vector<string> new_vec;
                new_vec.push_back(strs[i]);
                v_map[key] = new_vec;
            }
            else {
                v_map[key].push_back(strs[i]);
            }
        }
        for (map<string, vector<string> >::iterator i = v_map.begin(); i != v_map.end(); ++i) {
            
            // cout << i->first << endl;
            
            ans.push_back(i->second);
            // cout << i->second << endl;
        }
        return ans;
        // << " " << i->second
        
    }
    string getVal(string ori) {
        sort(ori.begin(), ori.end());
        return ori;
        
    } 
};

int main() {
    string input;
    cin >> input;
    input = input.substr(1, input.length() - 2);
    
    vector<string> strs;
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == ',')
        {
            input[i] = ' ';
        }
    }

    istringstream out(input);
    string row;
    while (out >> row)
    {
        row = row.substr(1, row.length() - 2);
        strs.push_back(row);
    }
    
    Solution S;
    vector<vector<string> > ans = S.groupAnagrams(strs);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
        
    }
    
    return 0;
}