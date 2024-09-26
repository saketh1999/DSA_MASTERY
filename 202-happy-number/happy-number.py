class Solution:
    def isHappy(self, n: int) -> bool:
        square_sum = 2
        myList = []
        while square_sum!=1 :
            
            my_sum = 0
            while n :
                my_sum+=(n%10)**2
                n=n//10
            
            if my_sum in myList:
                return False
            
            myList.append(my_sum)
            square_sum = my_sum
            n = my_sum
        print(n)
        return True
