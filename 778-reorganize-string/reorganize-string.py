class Solution:
    def reorganizeString(self, s: str) -> str:
        l_count = Counter(s)
        max_l = 0
        total_l = 0
        max_key = ""
        for key,value in l_count.items():
            if max_l < value:
                max_l = value
                max_key=key
           
            total_l+=value
        
        remaining = total_l - max_l
        if max_l > remaining+1:
            return ""

        res = ["" for i in range(len(s))]
        print(len(s),len(res))
        i=0
        while i < len(s) and max_l:
            res[i] = max_key
            max_l-=1
            i+=2
        

        keys = [key for key in l_count.keys() if key!=max_key]


        for key in keys:
            count = l_count[key]
            while count:
                if i>=len(s):
                    i=1
                
                res[i] = key
                count-=1
                i+=2

        return "".join(res)


