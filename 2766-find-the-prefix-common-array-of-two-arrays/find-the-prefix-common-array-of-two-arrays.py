class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        res = [0]*len(A)
        my_dict = {}
        for i in range(len(A)):
            my_dict[A[i]] = i

        for i in range(len(B)):
            if B[i] in my_dict:
                key = my_dict[B[i]]
                if key<i:
                    res[i]+=1
                else:
                    res[key]+=1
            if i!=0:
                res[i]+=res[i-1]
        
        return res