class Solution:
    def lenLongestFibSubseq(self, arr: List[int]) -> int:
        my_set = set(arr)
        res = 0
        for i in range(len(arr)-1):
            for j in range(i+1,len(arr)):
                prev, curr = arr[i],arr[j]
                next = prev+curr
                length = 2
                while next in my_set:
                    length+=1
                    res = max(res,length)

                    prev,curr = curr,next
                    next = prev+curr
        return res
