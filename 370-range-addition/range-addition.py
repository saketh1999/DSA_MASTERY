class Solution:
    def getModifiedArray(self, length: int, updates: List[List[int]]) -> List[int]:
        gradient_arr = [0]*(length+1)
        res = [0]*length

        for start,end,val in updates:
            gradient_arr[start]+=val
            gradient_arr[end+1]-=val
        
        res[0]=gradient_arr[0]

        for i in range(1,length):
            res[i]= gradient_arr[i]+res[i-1]
  
        
        return res


        