class Solution:
    def xorAllNums(self, nums1: List[int], nums2: List[int]) -> int:
        res = 0
        if  len(nums2)%2==1:
            for i in range(len(nums1)):
                res ^= nums1[i]
        if  len(nums1)%2==1:
            for i in range(len(nums2)):
                res^=nums2[i]

        return res