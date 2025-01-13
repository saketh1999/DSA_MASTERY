class Solution:
    def minimumLength(self, s: str) -> int:
        my_dict = Counter(s)

        res = 0

        for key,val in my_dict.items():
            while val >= 3:
                val-=2
            res+=val
        return res