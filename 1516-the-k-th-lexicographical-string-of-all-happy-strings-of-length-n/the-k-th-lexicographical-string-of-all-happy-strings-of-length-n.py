class Solution:
    def getHappyString(self, n: int, k: int) -> str:
        res = []
        my_set = set()
        given_arr = ['a','b','c']

        def helper(given_arr,temp,prev_char,n):
            if len(temp) == n:
                my_set.add("".join(temp))
                return
            
            for c in given_arr:
                if c==prev_char:
                    continue
                temp.append(c)
                helper(given_arr,temp,c,n)
                temp.pop(-1)
            return

            
        
        temp = []
        prev_char=""
        helper(given_arr,temp,prev_char,n)
        my_list = list(my_set)
        my_list.sort()

        
        if k > len(my_list):
            return ""
        return my_list[k-1]
        
        

