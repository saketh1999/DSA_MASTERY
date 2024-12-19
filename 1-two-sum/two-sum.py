class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        my_dict = {}
        for i in range(len(nums)):
            if target-nums[i] in my_dict:
                return [i,my_dict[target-nums[i]]]
            else:
                my_dict[nums[i]]=i
        