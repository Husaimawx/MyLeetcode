import os

# 弹出 x 的末尾数字 digit
# digit = x % 10
# x /= 10

# 将数字 digit 推入 rev 末尾
# rev = rev * 10 + digit

# class Solution {
# public:
#     int reverse(int x) {
#         int rev = 0;
#         while (x != 0) {
#             if (rev < INT_MIN / 10 || rev > INT_MAX / 10) {
#                 return 0;
#             }
#             int digit = x % 10;
#             x /= 10;
#             rev = rev * 10 + digit;
#         }
#         return rev;
#     }
# };

def reverse(x: int) -> int:
    y,res = abs(x), 0
    mark_code = (1 << 31) - 1 if x > 0 else 1 << 31

    while y:
        print ('in print')
        res = res*10 + y%10
        y //= 10
        if res > mark_code:
            return 0
    return res if x > 0 else -res

if __name__ == '__main__':
    print(reverse(32))