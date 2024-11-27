class Solution:
    def hammingWeight(self, n: int) -> int:
        cnt=0
        while n:
            print(fmod(n,2))
            if fmod(n,2)==1:
                cnt+=1
            n = n//2
        # if n==1: cnt+=1
        return cnt