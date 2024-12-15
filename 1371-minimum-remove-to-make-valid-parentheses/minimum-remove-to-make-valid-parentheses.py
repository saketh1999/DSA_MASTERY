class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        stack = []
        new_str = []
        for i in range(len(s)):
            new_str.append(s[i])
            if s[i]=='(':
                stack.append(s[i])
            if s[i]==')':
                if stack:
                    stack.pop(-1)
                else:
                    new_str.pop(-1)
        
        for i in range(len(new_str)-1,-1,-1):
            if stack:
                if new_str[i]=='(':
                    stack.pop()
                    new_str.pop(i)
                
        # while stack:
        #     new_str.remove('(')
        #     stack.pop()

        return "".join(new_str)
