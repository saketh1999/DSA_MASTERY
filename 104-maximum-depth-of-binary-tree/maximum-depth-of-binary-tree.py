# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def depth(self,root):
        if root == None:
            return 0
        
        left_h = self.depth(root.left)
        right_h = self.depth(root.right)

        return (1+max(left_h,right_h))

    def maxDepth(self, root: Optional[TreeNode]) -> int:
        return self.depth(root)