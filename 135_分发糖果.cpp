#include <iostream>
#include <string.h>
#include <sstream>
#include <vector>
using namespace std;

// 看着是困难，以为很难，看了题解，实际上就是贪心，第一遍只关心左邻居，第二遍只关心右邻居。

class Solution {
public:
    int candy(vector<int>& ratings) {
        // for (int i = 0; i < ratings.size(); i++)
        // {
        //     cout << ratings[i] << " ";
        // }
        // cout <<endl;

        int l = ratings.size();

        int* left = new int[l];
        int* right = new int[l];
        memset(left, 0, sizeof(l) * l);
        memset(right, 0, sizeof(l) * l);

        left[0] = 1;
        for (int i = 1; i < l; i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                left[i] = left[i - 1] + 1;
            }
            else {
                left[i] = 1;
            }
        }
        
        right[l - 1] = 1;
        for (int i = l - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                right[i] = right[i + 1] + 1;
            }
            else {
                right[i] = 1;
            }
        }
        
        int ans = 0;
        for (int i = 0; i < l; i++)
        {
            ans += max(left[i], right[i]);
        }
        return ans;
    }
};


int main () {
    string input1;
    cin >> input1;

    vector<int> ratings;

    input1 = input1.substr(1, input1.length());
    for (int i = 0; i < input1.length(); i++)
    {
        if (input1[i] == ',')
        {
            input1[i] = ' ';
        }
    }
    istringstream output1(input1);
    string temp1;
    while (output1 >> temp1)
    {
        ratings.push_back(atoi(temp1.c_str()));
    }
    
    Solution S;
    cout << S.candy(ratings);
    return 0;
}