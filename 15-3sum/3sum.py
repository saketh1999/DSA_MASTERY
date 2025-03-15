class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = set([])
        target=0
        nums.sort()

        for i in range(len(nums)):
            my_set = set([])
            my_tar = target - nums[i]
            for j in range(i+1,len(nums)):
                if nums[j] in my_set :
                    ans = [nums[i],nums[j],(my_tar-nums[j])]
                    # ans.sort()
                    res.add(tuple(ans))
                
                else:
                    
                    my_set.add(my_tar - nums[j])
        
        return list(res)