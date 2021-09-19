#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

// 可以考虑回溯法

class Solution {
public:
    vector<string> maps;
    void init() {
        maps.push_back("");
        maps.push_back("abc");
        maps.push_back("def");
        maps.push_back("ghi");
        maps.push_back("jkl");
        maps.push_back("mno");
        maps.push_back("pqrs");
        maps.push_back("tuv");
        maps.push_back("wxyz");
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        init();
        return digui(res, digits, 0);
    }
    vector<string> digui(vector<string> current, string digits, int pos) {
        // cout << "pos : " << pos << endl;
        if (pos == digits.length()) 
        {
            return current;
        }
        vector<string> new_current = current;
        char target = digits[pos];
        // cout << "target " << target<< endl;
        int p = target - '0' - 1;
        vector<string> new_new_current;
        for (int i = 0; i < maps[p].length(); i++)
        {
            if (current.size() == 0)
            {
                new_current.push_back(string(1,maps[p][i]));
            }
            else {
                for (int j = 0; j < current.size(); j++)
                {
                    new_new_current.push_back(current[j] + maps[p][i]);
                }
                new_current = new_new_current;
            }
        }
        return digui(new_current, digits, pos+1);
    }
};

// 输入：digits = "23"
// 输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
int main() {
    string input;
    cin >> input;
    Solution S;
    vector<string> output = S.letterCombinations(input);
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << endl;
    }
}