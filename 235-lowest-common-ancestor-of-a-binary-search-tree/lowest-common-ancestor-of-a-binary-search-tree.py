# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    

    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':

        def LCA_BST(root,p,q):
            if root == None or root.val == p.val or root.val == q.val:
                return root
            
            left_lca = LCA_BST(root.left,p,q)
            right_lca = LCA_BST(root.right,p,q)

            if left_lca is None:
                return right_lca
            elif right_lca is None:
                return left_lca
            else:
                return root
        return LCA_BST(root,p,q)

