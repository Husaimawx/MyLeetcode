#include <iostream>
#include <vector>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    while(k){
        int max_num = -45536;
        int pos = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > max_num){
                max_num = nums[i];
                pos = i;
            }
        }
        if(k == 1){
            return max_num;
        }
        nums.erase(nums.begin() + pos);
        k-- ;
    }
    return -1;
}
//[3,2,3,1,2,4,5,5,6]
//4

int main(){
    vector<int> test;
    test.push_back(3);
    test.push_back(2);
    test.push_back(3);
    test.push_back(1);
    test.push_back(2);
    test.push_back(4);
    test.push_back(5);
    test.push_back(5);
    test.push_back(6);
    cout << findKthLargest(test,4) << endl;;
    return 0;
}

/*
    0ms 答案
    
    class Solution {
    public:
        int findKthLargest(vector<int>& nums, int k) {
            sort(nums.begin(), nums.end());
            int len = nums.size();
            return nums[len - k];
        }
    };
*/





/*
    8ms 答案

    class Solution {
    public:
        int findKthLargest(vector<int>& nums, int k) {
            //小顶堆保存最大的k个数，对顶元素即是要找的第k大元素
            build_heap(heap, k, nums);
            for (int i = k; i < nums.size(); ++i) {
                if (nums[i] >= heap[0]) {
                    heap[0] = nums[i];
                    adjust_heap(heap, 0);
                }
            }
            return heap[0];
        }
    private:
        vector<int> heap;
        void put(vector<int>& heap, int num) {
            heap.push_back(num);
            int n = heap.size();
            int k = n - 1;
            int father = (k-1)/2;
            while (k > 0 && heap[k] < heap[father]) {
                adjust_heap(heap, father);
            }
        }
        void build_heap(vector<int>& heap, int k, vector<int>& nums) {
            for (int i = 0; i < k; ++i) {
                heap.push_back(nums[i]);
            }
            for (int i = k/2 - 1; i >= 0; i--) {
                adjust_heap(heap,i);
            }
            
        }
        void adjust_heap(vector<int>& heap, int k) {
            int l = k*2 + 1;
            int r = k*2 + 2;
            int len = heap.size() - 1;
            if (l > len) return;
            int min_idx = l;
            if (r <= len && heap[r] < heap[l]) {
                min_idx = r;
            }
            if (heap[k] > heap[min_idx]) {
                swap(heap[min_idx], heap[k]);
                adjust_heap(heap, min_idx);
            }

        }
    };
*/