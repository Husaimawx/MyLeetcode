/*
 * @Author: your name
 * @Date: 2021-02-25 13:09:08
 * @LastEditTime: 2021-02-25 14:59:23
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /LeetCode/6_Z字形变换.cpp
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;


// 思路：
// 不要去想每一行应该怎么得到
// 而是顺着去想每个字符应该去哪一行

string convert(string s, int numRows) {
	int n = s.length();
	if (numRows <= 1 || numRows >= n)
	{
		return s;
	}
	
	string* s_lists = new string[numRows];
	int cur_row = 0;
	bool going_down = true;
	for (int i = 0; i < n; i ++)
	{
		s_lists[cur_row].push_back(s[i]);
		if (going_down)
		{
			cur_row += 1;
		}
		else {
			cur_row -= 1;
		}
		if (cur_row == 0 || cur_row == numRows - 1)
		{
			going_down = !going_down;
		}
	}
	string ans;
	for (int i = 0; i < numRows; i++)
	{
		ans += s_lists[i];
	}
	return ans;
}
	
int main() {
	string input;
	cin >> input;
	cout << convert(input, 4) << endl;
	return 0;
}
