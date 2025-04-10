class Solution:
    def maximumCandies(self, candies: List[int], k: int) -> int:
        total_sum = sum(candies)
        if total_sum < k :
            return 0
        
        l,r = 1,total_sum//k
        res = 0
        while l<=r:
            count = 0
            mid = (l+r)//2

            for c in candies:
                if c >= mid:
                    count+= c//mid

                if count>=k:
                    break
            
            if count >= k :
                res = mid
                l = mid+1
            else:
                r = mid-1
        return res

