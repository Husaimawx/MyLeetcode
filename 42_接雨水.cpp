#include <iostream>
#include <string.h>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

// dp_left_max, dp_right_max
class Solution {
public:
    int ans;
    int trap(vector<int>& height) {
        ans = 0;
        int n = height.size();
        vector<int> left_max(n, 0);
        left_max[0] = 0;
        for (int i = 1; i < n; i++) {
            left_max[i] = max(left_max[i-1], height[i-1]);
        }
        vector<int> right_max(n, 0);
        right_max[n-1] = 0;
        for (int i = n-1; i >= 0; i--) {
            right_max[i] = max(right_max[i+1], height[i+1]);
        }

        // for (int i = 0; i < n; i++) {
        //     cout << left_max[i] << " ";
        // }
        // cout << endl;

        // for (int i = 0; i < n; i++) {
        //     cout << right_max[i] << " ";
        // }
        // cout << endl;

        // for (int i = 0; i < n; i++) {
        //     cout << height[i] << " ";
        // }
        // cout << endl;

        // for (int i = 0; i < n; i ++) {
        //     int temp = min(left_max[i], right_max[i]) - height[i];
        //     cout << temp << " ";
        //     ans += max(temp, 0);
        // }
        // cout << endl;
        return ans;
    }
};

int main () {
    vector<int > height;
    string input;
    cin >> input;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == ',') {
            input[i] = ' ';
        }
    }

    istringstream output(input);
    string temp;
    while (output >> temp)
    {
        height.push_back(atoi(temp.c_str()));
    }
    Solution S;
    cout << S.trap(height) << endl;
    
    return 0;
}