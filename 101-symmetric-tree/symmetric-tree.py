# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:

        def check_tree(root1,root2):
            if root1 is None and root2 is None:
                return True
            if root1 is None and root2 is not None:
                return False
            if root1 is not None and root2 is None:
                return False

            if root1.val==root2.val:
                return check_tree(root1.left,root2.right) and check_tree(root1.right,root2.left)
            else:
                return False
            


        root1=root2=root
        return check_tree(root1,root2)
