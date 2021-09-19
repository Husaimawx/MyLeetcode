#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i+1; j < nums.size(); j++)
        {
            if(nums[i] + nums[j] == target){
                ans.push_back(i);
                ans.push_back(j); 
            }
        }
    }
    return ans;
}

int main(){
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(4);
    nums.push_back(3);
    nums.push_back(0);
    
    vector<int> ans = twoSum(nums,0);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}


/*
    4ms 答案
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int,int> hashmap;
        for(int i = nums.size() - 1; i >= 0; --i){
            int another = target - nums[i];
            if(hashmap.count(another))
            {
                res = vector<int> ({hashmap[another], i});
                break;
            }
            hashmap[nums[i]] = i;
        }
        return res;
    }

*/


/*
    12ms 答案
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> tmp;
        for(int i = 0; i < nums.size(); i++){
            auto it = tmp.find(target - nums[i]);
            if(it != tmp.end()){
                result.push_back(it->second);
                result.push_back(i);
            }
            tmp.insert(pair<int, int>(nums[i], i));
        }
        return result;
    }
*/