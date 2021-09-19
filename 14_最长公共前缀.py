from typing import List

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        num = len(strs)
        if num == 0:
            return ''
        s = strs[0]
        MIN_LENGTH = 100005
        for i in range(num):
            print(strs[i])
            if len(strs[i]) < MIN_LENGTH:
                MIN_LENGTH = len(strs[i])
        cnt = 0
        while cnt < MIN_LENGTH:
            flag = True
            c = strs[0][cnt]
            for i in range(num):
                if not strs[i][cnt] == c:
                    flag = False
            if flag == True:
                cnt += 1
            else:
                break
        return strs[0][0:cnt]

if __name__ == '__main__':
    l = ['buff','buf','butter']
    print(Solution().longestCommonPrefix(l))


            
