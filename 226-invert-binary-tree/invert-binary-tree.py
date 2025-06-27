# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def invert_Binary_tree(root):
            if root is None:
                return
            invert_Binary_tree(root.left)
            invert_Binary_tree(root.right)
            root.left,root.right=root.right,root.left
            
        invert_Binary_tree(root)
        return root