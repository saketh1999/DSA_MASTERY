class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s2) < len(s1):
            return False

        s1_dict = {}
        s2_dict = {}

        small_start = ord('a')
        small_end = ord('z')

        #creating a directory of all characters
        for i in range(small_start,small_end+1):
            s1_dict[chr(i)] = 0
            s2_dict[chr(i)] = 0
        
        len_s1 = len(s1)

        for i in range(len_s1):
            s1_dict[s1[i]] += 1
            s2_dict[s2[i]] += 1
        
 

        l,r=0,len(s1)-1
        while r<len(s2):
            if s1_dict == s2_dict:
                return True
            
            r+=1
            if r<len(s2):
                s2_dict[s2[r]] += 1
            
            s2_dict[s2[l]]-=1
            l+=1
            

        return False

            
            
        