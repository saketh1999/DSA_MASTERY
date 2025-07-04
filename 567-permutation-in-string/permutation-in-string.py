class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False
        
        s1_dict = {}
        s2_dict = {}

        start = ord('a')
        end = ord('z')

        for i in range(start,end+1):
            s1_dict[chr(i)]=0
            s2_dict[chr(i)]=0

        for i in range(len(s1)):
            s1_dict[s1[i]]+=1
            s2_dict[s2[i]]+=1

        if s1_dict == s2_dict:
            return True
        

        l,r=0,len(s1)-1
        print(len(s2))
        while r<len(s2):
            if s1_dict == s2_dict:
                return True
            s2_dict[s2[l]]-=1
            l+=1
            r+=1
            if r<len(s2):
                s2_dict[s2[r]]+=1

        return False
        

      
        

        
                