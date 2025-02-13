# The knows API is already defined for you.
# return a bool, whether a knows b
# def knows(a: int, b: int) -> bool:

class Solution:
    def findCelebrity(self, n: int) -> int:
        #Step 1 : Do the elemination
        top,down = 0,n-1
        while top<down:
            if knows(top,down):
                top+=1
            elif knows(down,top):
                down-=1
            else:
                top+=1
                down-=1

        if top>down:
            return -1
        
        for i in range(n):

            if i == top:
                continue

            if knows(top,i):
                return -1
            elif not knows(i,top):
                return -1
        
        return top