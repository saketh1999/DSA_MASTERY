# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        def lca_bst(temp):

            if temp.val < p.val and temp.val<q.val: #p=7,q=9
                return lca_bst(temp.right)
            elif temp.val>p.val and temp.val>q.val: #p=3,q=5
                return lca_bst(temp.left)
            else: 
                return temp
            
        return lca_bst(root)
                
                
            
            