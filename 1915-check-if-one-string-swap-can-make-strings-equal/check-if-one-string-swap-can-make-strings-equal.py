class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        
        diff_index = []

        n = len(s2)

        for i in range(0,n):
            if s1[i] != s2[i]:
                diff_index.append(i)
            if len(diff_index) >2:
                return False
        
        if len(diff_index) == 2:
            i,j = diff_index[0],diff_index[1]
            if s1[i] == s2[j] and s1[j] == s2[i]:
                return True
            return False
        
        if len(diff_index) == 0:
            return True
        
        return False