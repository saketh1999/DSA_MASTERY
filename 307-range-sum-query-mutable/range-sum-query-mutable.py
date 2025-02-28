class SegmentNode:
    def __init__(self,start,end,val):
        self.start = start
        self.end = end
        self.val = val
        self.left = None
        self.right = None

class NumArray:

    def __init__(self, nums: List[int]):
        #build the tree
        def build(nums,left,right):
            if left == right:
                return SegmentNode(left,right,nums[left])
            mid = (left+right)//2

            root = SegmentNode(left,right,nums[left])

            root.left = build(nums,left,mid)
            root.right = build(nums,mid+1,right)

            root.val = root.left.val + root.right.val

            return root
        self.root = build(nums,0,len(nums)-1)


    def update(self, index: int, val: int) -> None:
        def updateVal(root,index,val):
            if root.start == root.end:
                root.val = val
                return 

            mid = (root.start+root.end)//2
            if index > mid:
                updateVal(root.right,index,val)
            else:
                updateVal(root.left,index,val)
            
            root.val = root.right.val + root.left.val
            


        return updateVal(self.root,index,val)
        

    def sumRange(self, left: int, right: int) -> int:
        def sumUpdate(root,start,end):
            if root.start == start and root.end == end:
                
                return root.val
            
            mid = (root.start+root.end)//2

            if start > mid :
                return sumUpdate(root.right,start,end)
            elif end<=mid:
               return sumUpdate(root.left,start,end)
            else:
                return sumUpdate(root.left,start,mid)+ sumUpdate(root.right,mid+1,end)
        return sumUpdate(self.root,left,right)


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# obj.update(index,val)
# param_2 = obj.sumRange(left,right)