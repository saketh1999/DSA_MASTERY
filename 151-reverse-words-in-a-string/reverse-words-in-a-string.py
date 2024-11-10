class Solution:
    def reverseWords(self, s: str) -> str:
       temp = s.strip()  
       temp = temp.split()
       temp = temp[::-1]
       return " ".join(temp)
