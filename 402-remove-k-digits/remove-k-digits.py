class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        stack = []
        for i in range(len(num)):
            while stack and k>0 and int(stack[-1]) > int(num[i]):
                stack.pop(-1)
                k-=1
            stack.append(num[i])


        print(stack)
        if not stack:
            return "0"
        while stack and k:
            stack.pop(-1)
            k-=1

        res = "".join(stack)
        res=res.lstrip('0')

        if not res:
            return "0"
        return res

