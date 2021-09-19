#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

// 0 未覆盖
// 1 已覆盖
// 2 装监控
int cnt = 0;

int traverse(const vector<int>& lch, const vector<int>& rch, int index) {
	if (!index) return 1;

	int l = traverse(lch, rch, lch[index]);
	int r = traverse(lch, rch, rch[index]);

	// 中间结点
	if (l==1&&r==1) {
		return 0;
	}
	else if (!l || !r) {
		cnt++;
		return 2;
	}
	else if (l == 2 || r == 2) {
		return 1;
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> lch(n + 1, 0);
	vector<int> rch(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> lch[i] >> rch[i];
	}

	int root = traverse(lch, rch, 1);
	if (!root)cnt++;
	cout << cnt << endl;

	return 0;
}