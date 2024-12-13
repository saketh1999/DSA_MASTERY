# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def trav_tree(self,root,target):
        if root is None:
            return False
    
        
        target-=root.val
        if root.left is None and root.right is None and target==0:
            return True
        #left
        left=self.trav_tree(root.left,target)
        #right
        right=self.trav_tree(root.right,target)
    

        if right or left:
            return True
        return False
        
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:

        if root is not None:
            return self.trav_tree(root,targetSum)
        return False