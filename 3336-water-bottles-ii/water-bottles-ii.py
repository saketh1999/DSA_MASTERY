class Solution:
    def maxBottlesDrunk(self, numBottles: int, numExchange: int) -> int:
        total = 0
        empty_bottles = 0

        #intially complete all numBottles
        empty_bottles = numBottles
        total+=numBottles

        while empty_bottles >= numExchange :
            #exhange 
            empty_bottles-=numExchange
            #empty the new bottle
            total+=1
            #add the empty bottle
            empty_bottles+=1
            #increment the numExchange
            numExchange+=1
        
        return total
            