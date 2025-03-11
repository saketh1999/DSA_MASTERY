class Solution:
    def rankTeams(self, votes: List[str]) -> str:
        d = {}
        ##Create the dictionary that will add the letters and word
        for vote in votes:
            for i, char in enumerate(vote):
                if char not in d:
                    d[char] = [0] * len(vote)
                d[char][i] += 1
        
        #now stort them in ascending order
        voted_names = sorted(d.keys())

        #then sort them based on the values in reverse order(because)
        v = sorted(voted_names, key=lambda x: d[x], reverse=True)

        return "".join(v)