class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        if len(s) < k:
            return False
        
        word_count = Counter(s)
        odd = 0
        for c,count in word_count.items():
            if count%2 != 0 :
                odd+=1
        
        return odd <=k 