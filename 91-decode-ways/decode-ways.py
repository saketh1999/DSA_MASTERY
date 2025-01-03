class Solution:
    def numDecodings(self, s: str) -> int:
        if s[0]=='0':
            return 0
        
        dp = [-1 for i in range(len(s)+1)]

        def decode(s,i):
            
            if i==len(s):
                    return 1
            if s[i]=='0':
                    return 0
            
            if dp[i]!=-1:
                return dp[i]

            #select one
            one = decode(s,i+1)
            print("i:",i,"one",one)

            #select two
            two=0
            res = decode(s,i + 1)
            if i+1 < len(s):
                if (s[i] == '1' or 
                   (s[i] == '2' and s[i + 1] < '7')):
                        two += decode(s,i+2)


            dp[i] = one + two
            return dp[i]

        def decode_BU(s):
            n=len(s)
            dp[n] = 1

            for i in range(n-1,-1,-1):
                
                if s[i] =='0':
                    dp[i]=0

                else:
                    ways = dp[i+1]

                    if  i+1 < len(s):
                        if (s[i] == '1' or (s[i] == '2' and s[i + 1] < '7')):
                            ways+=dp[i+2]

                    dp[i] = ways
                    
    
            return dp[0]

        def decode_BU_spaceOptimized(s):
            n=len(s)
            prev = 1
            prev2=-1

            for i in range(n-1,-1,-1):
                curr=-1
                if s[i] =='0':
                    curr=0

                else:
                    ways = prev

                    if  i+1 < len(s):
                        if (s[i] == '1' or (s[i] == '2' and s[i + 1] < '7')):
                            ways+=prev2
                    
                    curr = ways
                prev2 = prev
                prev = curr
                            
        
                    
    
            return curr
        return decode_BU_spaceOptimized(s)
        return decode_BU(s)
        return decode(s,0)