class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        myDict = {}

        for i,val in enumerate(s):
                myDict[val] = i


        
        length = 0
        end = 0
        sol = []
        for i,x in enumerate(s):
            if end < myDict[x]:
                end = myDict[x]
            length+=1

            if i==end:
                sol.append(length)
                length=0
        
        return sol