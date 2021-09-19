class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x<0:
            return False
        y = 0
        temp_x = x
        while temp_x:
            y = y*10 + temp_x%10
            temp_x //= 10
        return y == x

if __name__ == '__main__':
    print(Solution().isPalindrome(11))
