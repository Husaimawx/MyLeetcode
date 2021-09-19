#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();
        if (m == 0) return n == 0;
        if (m == 1) {
            if (n > 1)return false;
            if (flowerbed[0] == 0) return true;
            return n == 0;
        }
        int max_cnt = 0;
        if (flowerbed[0] == 0 && flowerbed[1] != 1) {
            max_cnt ++;
            flowerbed[0] = 1;
        }
        for (int i = 1; i < m-1; i++) {
            if (flowerbed[i] == 0 && flowerbed[i-1] != 1 && flowerbed[i+1] != 1) {
                max_cnt ++;
                flowerbed[i] = 1;
            }
        }
        if (flowerbed[m-2] == 0 && flowerbed[m-1] == 0) {
            max_cnt ++;
        }
        return max_cnt >= n;
    }
};