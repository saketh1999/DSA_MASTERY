class Solution:
    def sumOfBeauties(self, nums: List[int]) -> int:
        n=len(nums)
        greatest = [-nums[0]]
        smallest = []
        sum=0
        for i in range(2,n):
            smallest.append(nums[i])
        
        heapq.heapify(greatest)
        heapq.heapify(smallest)

   
        for i in range(1,n-1):
            upper = smallest[0]
            lower = -greatest[0]
            print(lower,upper)

            if lower<nums[i] and nums[i]<upper:
                sum+=2
            elif nums[i-1]<nums[i] and nums[i]<nums[i+1]:
                sum+=1
            heapq.heappush(greatest,-nums[i])
            heapq.heappop(smallest)
            print(sum,i)
        return sum