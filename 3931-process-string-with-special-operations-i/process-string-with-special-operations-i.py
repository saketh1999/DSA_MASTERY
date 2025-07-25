class Solution:
    def processStr(self, s: str) -> str:
        res =[]
        for char in s:
            if char == '*':
                if res:
                    res.pop(-1)
            elif char == '#':
                if res:
                    dup = res.copy()
                    for c in dup:
                        res.append(c)

            elif char == '%':
                if res:
                    res=res[::-1]

            else:
                res.append(char)

        return "".join(res)
