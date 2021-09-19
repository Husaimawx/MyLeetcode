#include <iostream>
#include <set>
#include <string.h>
#include <sstream>
#include <vector>
using namespace std;


// 同样的拼接问题，还是用动态规划，
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> mySet = set<string> ();
        for (int i = 0; i < wordDict.size(); i++)
        {
            mySet.insert(wordDict[i]);
        }
        bool * dp = new bool[s.length() + 1];
        dp[0] = true;

        // bool test = mySet.find("leet") != mySet.end();
        // cout << test << endl;
        for (int i = 1; i < s.length() + 1; i++)
        {
            for (int j = 0; j < i; j++)
            {
                dp[i] = dp[i] || (dp[j] && (mySet.find(s.substr(j, i-j)) != mySet.end()));
            }   
        }
        
        // for (int i = 0; i < s.length() + 1; i++)
        // {
        //     cout << dp[i] << " ";
        // }
        // cout << endl;
        return dp[s.length()];
    }
};


int main () {
    string s = "applepenapple";
    vector<string> wordDict;
    wordDict.push_back("apple");
    wordDict.push_back("pen");

    Solution S;
    cout << S.wordBreak(s, wordDict) << endl;;

    return 0;
}