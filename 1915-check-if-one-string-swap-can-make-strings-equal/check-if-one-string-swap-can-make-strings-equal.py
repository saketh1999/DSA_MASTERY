class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        if s1 == s2:
            return True
        str1 = list(s1)
        str2 = list(s2)
        n = len(s1)
        for i in range(0,n):
            for j in range(1,n):

                str2[i],str2[j] = str2[j],str2[i]

                if str2 == str1:
                    return True
                    
                str2[i],str2[j] = str2[j],str2[i]
        
        return False