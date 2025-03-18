class Solution:
    def getModifiedArray(self, length: int, updates: List[List[int]]) -> List[int]:

        res = [0]*length
        for start,end,val in updates:
            res[start]+=val
            if end<length-1:
                res[end+1]-=val
        
        for i in range(1,length):
            res[i]= res[i]+res[i-1]
  
        
        return res


        