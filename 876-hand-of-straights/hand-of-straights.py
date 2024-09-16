class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        
        if len(hand)%groupSize != 0 :
            return False

        ##Creating a Dictionary
        myDict= {}
        for x in hand:
            if x in myDict:
                myDict[x] +=1
            else:
                myDict[x] = 1

        ##Creating a min heap for the keys
        myheap = list(myDict.keys())
        heapq.heapify(myheap) #min heap

        ##Traversing the hand
        while myheap:
            first = myheap[0]

            for i in range(first,first + groupSize):
                if i not in myDict:
                    return False

                myDict[i] -= 1
                if myDict[i] == 0:
                    # if i != myheap[0]: # this is because, 1,2,3 example
                    #     return False
                    heapq.heappop(myheap)

        return True