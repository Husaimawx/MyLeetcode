#include <iostream>
#include <vector>
#include <string>
using namespace std;


vector<char> arrays;
class Solution {
public:
    void reverseString(vector<char>& s) {
        int len = s.size();
        for (int i = 0; i < s.size()/2; i++)
        {
            char c = s[i];
            s[i] = s[len - i - 1];
            s[len - i - 1] = c;
        }
    }
};

int main(){
    string input;
    cin >> input;
    input = input.substr(1);
    input = input.erase(input.length() - 1);
    string temp;
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == ',')
        {
            temp = temp.substr(1);
            temp = temp.erase(temp.length() - 1);
            arrays.push_back(temp[0]);
            temp = "";
        }
        else
        {
            temp.push_back(input[i]);
        }
    }
    temp = temp.substr(1);
    temp = temp.erase(temp.length() - 1);
    arrays.push_back(temp[0]);

    for (int i = 0; i < arrays.size(); i++)
    {
        cout << arrays[i] << endl;
    }
    
    cout << endl;
    Solution S;
    S.reverseString(arrays);


    for (int i = 0; i < arrays.size(); i++)
    {
        cout << arrays[i] << endl;
    }

    return 0;
}