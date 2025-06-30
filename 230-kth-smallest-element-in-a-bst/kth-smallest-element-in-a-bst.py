# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        count = 0
        sol = root.val
        def trav(node):
            nonlocal count
            nonlocal sol
            if node is None:
                return
            
            trav(node.left)
            count+=1
            if count==k:
                sol = node.val
                return
            trav(node.right)
        trav(root)
        return sol

