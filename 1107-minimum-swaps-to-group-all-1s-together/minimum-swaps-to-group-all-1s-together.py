class Solution:
    def minSwaps(self, data: List[int]) -> int:
        left,right=0,0
        total_one = 0
        max_cnt_one = 0
        cnt_one = 0

        for i in range(len(data)):
            if data[i]:
                total_one+=1

        while right<len(data):

            cnt_one += data[right] 
            right+=1

            if right-left>total_one:
                cnt_one -=data[left]
                left+=1
            
            max_cnt_one = max(max_cnt_one,cnt_one)
                
          
        
        return total_one-max_cnt_one
                
