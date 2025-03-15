class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        my_dict = {}
        for x in strs:
            w_count = [0 for i in range(26)]

            for c in x:
                w_count[ord(c)-ord('a')]+=1

            if tuple(w_count) not in my_dict:
                my_dict[tuple(w_count)]=[]
            my_dict[tuple(w_count)].append(x)
        
        res = []
        for key in my_dict.keys():

            res.append(my_dict[key])
        return res
            
                