class Solution:
    def tupleSameProduct(self, nums: List[int]) -> int:
        myDict = defaultdict(int)

        for i in range(len(nums)):
            for j in range(i+1,len(nums)):
                product = nums[i] * nums[j]
                myDict[product]+=1
            
        
        res =0
        for count in myDict.values():
            pairs = (count * (count-1))//2

            res += pairs * 8
        
        return res

