# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        def isBST(root,left_val,right_val):
            if root is None:
                return True
            
            if not (left_val<root.val<right_val):
                return False
            
            left = isBST(root.left,left_val,root.val)
            right = isBST(root.right,root.val,right_val)

            return left and right
        
        return isBST(root,float(-inf),float(inf))