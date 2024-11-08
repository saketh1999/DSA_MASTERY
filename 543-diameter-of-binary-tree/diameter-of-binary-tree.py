# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def height(self,root):
        if root == None:
            return 0

        left_t = self.height(root.left)
        right_t = self.height(root.right)
        self.diameter = max(self.diameter,left_t+right_t)
        return (1+max(left_t,right_t))


    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.diameter = 0
        self.height(root)
        return self.diameter