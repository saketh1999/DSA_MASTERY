class Solution:
    def wordSubsets(self, words1: List[str], words2: List[str]) -> List[str]:
        word_2_count = defaultdict(int)

        for w in words2:
            word_count = Counter(w)
            for c,count in word_count.items():
                word_2_count[c] = max(word_2_count[c],count)
        
        res = []
        for w in words1:
            count_1 = Counter(w)
            flag1=True
            for c in word_2_count.keys():
                if count_1[c]<word_2_count[c]:
                    flag1=False
                    break
            if flag1:
                res.append(w)
            
        return res
            
