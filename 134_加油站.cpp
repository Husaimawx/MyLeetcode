#include <iostream>
#include <string.h>
#include <sstream>
#include <vector>
using namespace std;

// 一看到加油站想起了之前考试里遇到的一个类似的动态规划题，就想着用dp做，结果怎么想都没想出来
// 其实这个题就是一个简单的数学优化题。
// 暴力求解的话，把每个点当作起点试一遍，但是可以发现，如果从第i个点走到第j个点之后发现走不到了，那从i到j之间的点就可以跳过不用考虑。

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int l = gas.size();
        int i = 0;
        while (i < l)
        {
            int sum_gas = 0; 
            int sum_cost = 0;
            int cnt = 0;
            while (cnt < l)
            {
                int pos = i + cnt;
                pos = pos % l;
                sum_gas += gas[pos];
                sum_cost += cost[pos];
                if (sum_cost > sum_gas)
                {
                    break;
                }
                cnt ++;
            }
            if (cnt == l)
            {
                return i;
            }
            else {
                i = i + cnt + 1;
            }
            
        }
        
        
        return -1;
    }
};
// [1,2,3,4,5]
// [3,4,5,1,2]
int main () {
    string input1, input2;
    cin >> input1 >> input2;

    vector<int> gas;
    vector<int> cost;

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
        gas.push_back(atoi(temp1.c_str()));
    }
    
    
    input2 = input2.substr(1, input2.length());
    for (int i = 0; i < input2.length(); i++)
    {
        if (input2[i] == ',')
        {
            input2[i] = ' ';
        }
    }
    istringstream output2(input2);
    string temp2;
    while (output2 >> temp2)
    {
        cost.push_back(atoi(temp2.c_str()));
    }

    Solution S;
    cout << S.canCompleteCircuit(gas, cost);
    return 0;
}