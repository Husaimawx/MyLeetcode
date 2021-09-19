#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    unordered_set<int> s;
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            s.insert(nums[i]);
        }
        int i = 1;
        while(s.find(i) != s.end()) {
            i++;
        }
        return i;
    }
};