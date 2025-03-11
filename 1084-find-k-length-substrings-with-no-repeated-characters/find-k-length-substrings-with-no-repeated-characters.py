class Solution:
    def numKLenSubstrNoRepeats(self, s: str, k: int) -> int:
        my_set = []

        left,right = 0,0
        count = 0

        while right < len(s):
            while s[right] in my_set and left<=right:
                # print(my_set,s[right])
                my_set.pop(0)
                left+=1

            my_set.append(s[right])

            if right-left+1>k:
                my_set.pop(0)
                left+=1
            

            if len(my_set)==k:
                # print(my_set)
                count+=1
            
            right+=1
        
        return count