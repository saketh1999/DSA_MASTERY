class SparseVector:
    def __init__(self, nums: List[int]):
        self.my_vec = nums

    # Return the dotProduct of two sparse vectors
    def dotProduct(self, vec: 'SparseVector') -> int:
        _size = len(self.my_vec)
        product=0
        for i in range(_size):
            product+= self.my_vec[i] * vec.my_vec[i]
        return product


# Your SparseVector object will be instantiated and called as such:
# v1 = SparseVector(nums1)
# v2 = SparseVector(nums2)
# ans = v1.dotProduct(v2)