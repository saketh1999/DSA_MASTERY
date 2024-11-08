# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def traverse_tree(self,root1,root2):
        if root1 == root2 == None:
            return True
        if root1 == None and root2 != None:
            return False
        if root2 == None and root1 != None:
            return False
            
        left,right = False,False
        if root1.val == root2.val :
            print(root1.val,root2.val)
            left = self.traverse_tree(root1.left,root2.left)
            right = self.traverse_tree(root1.right,root2.right)
        
        return left and right
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        return self.traverse_tree(p,q)