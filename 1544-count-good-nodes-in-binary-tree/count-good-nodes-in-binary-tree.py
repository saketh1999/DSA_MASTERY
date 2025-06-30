# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    
    def goodNodes(self, root: TreeNode) -> int:
        count = 0
        def inorder_trav(root,maxVal):    
            nonlocal count
            if root is None:
                return
            if root.val >= maxVal:
                count+=1
                maxVal = root.val
            inorder_trav(root.left,maxVal)
            inorder_trav(root.right,maxVal)
            
        inorder_trav(root,-math.inf)
        return count
