class Solution:
    def prefixCount(self, words: List[str], pref: str) -> int:
        count = 0
        N = len(pref)
        for w in words:
            if N >len(w):
                continue
            if w[:N] == pref:
                count+=1
        
        return count