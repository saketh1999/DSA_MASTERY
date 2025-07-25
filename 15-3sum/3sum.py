class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        sol = []

        for i,a in enumerate(nums):
            if i>0 and nums[i] == nums[i-1]:
                continue

            l,r=i+1,len(nums)-1

            while l<r:            
                
                if nums[i]+nums[l]+nums[r] > 0:
                    r-=1

                elif nums[i]+nums[l]+nums[r] <0 :
                    l+=1

                elif nums[i]+nums[l]+nums[r]==0:
                        sol.append([nums[i],nums[l],nums[r]])

                        l+=1
                        while nums[l]==nums[l-1] and l<r:
                            l+=1
        return sol