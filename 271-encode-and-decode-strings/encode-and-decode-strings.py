class Codec:
    def encode(self, strs: List[str]) -> str:
        """Encodes a list of strings to a single string.
        
        """
        #you can use any 
        res = ""
        for s in strs:
            res+= str(len(s))+"#"+s
        return res
        

    def decode(self, s: str) -> List[str]:
        """Decodes a single string to a list of strings.
        """
        sol = []
        i = 0
        while i <len(s):
            j=i
            while s[j]!="#":
                j+=1
            str_len = int(s[i:j])
            i=j+1
            j=j+str_len
            sol.append(s[i:j+1])
            i=j+1
        return sol


        


# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(strs))