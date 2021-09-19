#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getMaxMatrix(vector<vector<int> >& matrix) {

        int m = matrix.size(), n = matrix[0].size();
        int maxMat = INT_MIN;
        vector<int> ans(4, -1);

        for (int r1 = 0; r1 < m; ++r1){             //遍历起始行
            vector<int> nums(n);                    //按列求和
            for (int r2 = r1; r2 < m; ++r2){        //遍历结束行
                
                int dp=0, start = -1;

                for (int i = 0; i < n; ++i){        //遍历和数组，实际上是边遍历边完成求和
                    nums[i] += matrix[r2][i];       //将新的一行中第i个元素加到前面若干行在位置i的和
                    if (dp > 0){                    //前面的字段有和为正，可以把前面一部分也带上
                        dp += nums[i];
                    }
                    else {                          //前面一段为负，拖后腿直接抛弃
                        dp = nums[i];
                        start = i;
                    }
                    if (dp > maxMat) {              //不断记录较好的结果
                        maxMat = dp;
                        ans[0] = r1;
                        ans[1] = start;
                        ans[2] = r2;
                        ans[3] = i;
                    }
                }
            }
        }
        return ans;
    }
};

int main () {


    return 0;
}