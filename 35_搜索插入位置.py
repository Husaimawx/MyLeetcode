from typing import List

class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        size = len(nums)
        pos = 0
        for i in nums:
            if i == target:
                return pos
            elif i > target:
                return pos
            pos += 1
        return size


if __name__ == '__main__':
    li = list(map(int,input().split()))
    print(Solution().searchInsert(li,0))