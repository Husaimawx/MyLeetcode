#include <iostream>
#include <string>
#include <vector>
using namespace std;



class Solution {
public:
    void sortColors(vector<int>& nums) {
        bool flag = true;
        int temp;
        while (flag)
        {
            bool single = false;
            for (int i = 1; i < nums.size(); i++)
            {
                if (nums[i] < nums[i-1])
                {
                    temp = nums[i];
                    nums[i] = nums[i-1];
                    nums[i-1] = temp;
                    single = true;
                }
            }
            if (single == false)
            {
                flag = false;
            }
        }
    }
    void displayArray(vector<int>& arrays){
        for (int i = 0; i < arrays.size(); i++)
        {
            cout << arrays[i] << endl;
        }
        cout << endl;
    }
};


int main(){
    string input;
    vector<int> arrays;
    cin >> input;
    input = input.substr(1);
    input = input.erase(input.length() - 1);
    cout << input << endl;  
    string temp;
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == ',')
        {
            arrays.push_back(atoi(temp.c_str()));
            temp = "";
        }
        else
        {
            temp.push_back(input[i]);
        }
    }
    arrays.push_back(atoi(temp.c_str()));
    
    Solution S;
    S.displayArray(arrays);
    S.sortColors(arrays);
    S.displayArray(arrays);
    return 0;
}


// void sortColors(vector<int>& nums) {
//         int t = 0, pos = 0;
//         int l = 0, r = nums.size() - 1;
        
//         while(pos <= r)
//         {
//             switch(nums[pos]) {
//                 case 0:
//                 swap(l, pos);
//                 ++l;
//                 ++pos;
//                 break;
//                 case 1:
//                 ++pos;
//                 break;
//                 case 2:
//                 swap(r, pos);
//                 --r;
//                 break;
//             }
//         }
//         return;
// }