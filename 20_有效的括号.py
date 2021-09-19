class Stack:
    def __init__(self):
        self.items = []
    
    def isEmpty(self):
        return self.items == []
    
    def push(self, item):
        self.items.append(item)
    
    def pop(self):
        return self.items.pop()
    
    def peek(self):
        return self.items[-1]
    
    def size(self):
        return len(self.items)

class Solution:
    def isValid(self, s: str) -> bool:
        stack = Stack()
        cnt_yuan = 0
        cnt_fang = 0
        cnt_da = 0

        length = len(s)
        for i in s:
            if i == '(':
                stack.push('(')
            if i == '[':
                stack.push('[')
            if i == '{':
                stack.push('{')
            if i == ')':
                if stack.isEmpty():
                    return False
                c = stack.pop()
                if c != '(':
                    return False
            if i == ']':
                if stack.isEmpty():
                    return False
                c = stack.pop()
                if c != '[':
                    return False
            if i == '}':
                if stack.isEmpty():
                    return False
                c = stack.pop()
                if c != '{':
                    return False
        if stack.isEmpty():
            return True
        else:
            return False

        



if __name__ == '__main__':
    s = input()
    print(Solution().isValid(s))


'''
class Solution:
    def isValid(self, s: str) -> bool:
        if not s:
            return True
        stack = []
        for i in s:
            if i in ['(', '{', '[']:
                stack.append(i)
            else:
                if not stack:
                    return False
                if i == ')' and stack[-1] == '(':
                    stack.pop()
                    continue
                if i == '}' and stack[-1] == '{':
                    stack.pop()
                    continue
                if i == ']' and stack[-1] == '[':
                    stack.pop()
                    continue
                else:
                    return False
        if stack:
            return False
        return True
'''