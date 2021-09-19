#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        int first = nums[0];
        for (int i = 1; i < nums.size(); i ++ ){
            first ^= nums[i];
        }
        int div = 1;
        while ((div & first) == 0)
            div <<= 1;
            
        int a = 0, b = 0;
        for (int n = 0; n < nums.size(); n ++)
            if (div & nums[n])
                a ^= nums[n];
            else
                b ^= nums[n];
        return {a, b};
    }
};