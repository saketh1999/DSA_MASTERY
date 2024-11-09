# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.max_val = float(-inf)
        def maxPath(root,max_val):
            
            if root is None:
                return 0
            
            left = max(0,maxPath(root.left,self.max_val))
            right = max(0,maxPath(root.right,self.max_val))

            self.max_val = max(self.max_val,root.val+left+right)

            return root.val + max(left,right)

        maxPath(root,self.max_val)
        return self.max_val