class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        key_dir = {'2': "abc",'3':"def",'4':"ghi",'5':"jkl",'6':"mno",'7':"pqrs",'8':"tuv",'9':"wxyz"}
        res = []
        
        

        def combination(self,digits,i,sub_str):
            if i >= len(digits):
                if sub_str == "":
                    return
                res.append(sub_str)
                return
            
            curr_str = key_dir[digits[i]]

            for x in curr_str:
                combination(self,digits,i+1,sub_str+x)
            
        combination(self,digits,0,"")
        return res
