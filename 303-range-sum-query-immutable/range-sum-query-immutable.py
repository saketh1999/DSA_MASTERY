class NumArray:

    def __init__(self, nums: List[int]):
        self.prefix_sum =[]
        self.total = 0
        for i in range(len(nums)):
            self.total+=nums[i]
            self.prefix_sum.append(self.total)


    def sumRange(self, left: int, right: int) -> int:
        preRight = self.prefix_sum[right]
        preLeft=0
        if left - 1 >=0:
            preLeft = self.prefix_sum[left-1]
        return preRight-preLeft

        


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(left,right)