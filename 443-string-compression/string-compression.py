class Solution:
    def compress(self, chars: List[str]) -> int:
        count=0
        l,r=0,0
        sol=""
        while r <len(chars):
            if chars[l]==chars[r]:
                count+=1
            else:
                sol+=chars[l]
                if count>1:
                    sol+=str(count)
                l=r
                print(count)
                print(l)
                count=1
            r+=1
            # print(r)
        
        sol+=chars[l]
        if count>1:
            sol+=str(count)


        res = [c for c in sol]

        for i in range(len(res)):
            chars[i]=res[i]
     
        return  len(sol)
            

