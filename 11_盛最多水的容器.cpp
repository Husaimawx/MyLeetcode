#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 不要一上来就想动态规划，尤其是这种题目，转移方程不好找
// 双指针：每次都移动自己最差的一边


int min (int i, int j){
    if (i <= j)
    {
        return i;
    }
    else{
        return j;
    }
}
int maxArea(vector<int>& height) {
    int i,j;
    i = 0;
    j = height.size() - 1;
    
    int max_size = -1;

    while (i < j)
    {
        int temp_size = (j - i) * min(height[i],height[j]);
        if (temp_size > max_size)
        {
            max_size = temp_size;
        }
        if (height[i] <= height[j])
        {
            i += 1;
        }
        else {
            j -= 1;
        }
        
    }
    return max_size;
}
int main(){
    vector<int> numbers;
    string s;

    cin >> s;
    int pos = s.find(',');
    while(pos != s.npos){
        string temp = s.substr(0, pos);
        
        numbers.push_back(atoi(temp.c_str()));
        s= s.substr(pos+1, s.size());
        pos = s.find(',');
    }
    numbers.push_back(atoi(s.c_str()));

    for (int i = 0; i < numbers.size(); i++)
    {
        cout << numbers[i] << endl;
    }
    
    cout << maxArea(numbers);
    
    return 0;
}