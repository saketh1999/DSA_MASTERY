class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        dic = {}
        for num in nums:
            if num in dic:
                dic[num]+=1
            else:
                dic[num]=1
        sol = []
        heap=[]
        for num,val in dic.items():
            heappush(heap,[-val,num])
        
        for i in range(k):
            val,num = heappop(heap)
            sol.append(num)
        return sol
            