class Solution:
    def isValid(self, s: str) -> bool:
        stack = []

        for i in range(len(s)):
            
            if s[i]=='(':
                stack.append(s[i])
            elif s[i]=='{':
                stack.append(s[i])
            elif s[i]=='[':
                stack.append(s[i])
            
            if not stack:
                return False
            elif s[i] ==']':
                if stack[-1] != '[':
                    return False
                else:
                   stack.pop(-1)

            elif s[i]=='}':
                if stack[-1]!='{':
                    return False
                else:
                    stack.pop(-1)
            elif s[i]==')':
                if stack[-1]!='(':
                    return False
                else:
                    stack.pop(-1)
        if stack:
            return False
        return True
