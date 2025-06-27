# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    

    def isBalanced(self, root: Optional[TreeNode]) -> bool:



        def height(root):
            if root == None :
                return 0
            left = height(root.left)
            right = height(root.right)
            if left <0 or right<0 or abs(left-right)>1: return -1

            return 1+max(left,right)

        if height(root) == -1:
            return False
        return True