class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        ind_a,ind_b,ind_c = -1,-1,-1

        count = 0

        for i in range(len(s)):
            if s[i] == 'a':
                ind_a = i
            elif s[i] == 'b':
                ind_b = i
            elif s[i] == 'c':
                ind_c = i
            
            if ind_a!=-1 and ind_b!=-1 and ind_c!=-1:
                count += 1+ min(ind_a,ind_b,ind_c)
        return count

