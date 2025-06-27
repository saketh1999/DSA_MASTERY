# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        

        def traverse(root1,root2):
            if root1 is None and root2 is None :
                return True
            if root1 is None and root2 is not None:
                return False
            if root1 is not None and root2 is None:
                return False
            
            left,right = False,False
            if root1.val == root2.val:
                left = traverse(root1.left,root2.left)
                right = traverse(root1.right,root2.right)

            return left and right


        def inorder(node1,node2):
            if node1 is None:
                return False
            if node2 is None:
                return True
            
            if node1.val == node2.val and traverse(node1,node2):

                return True
            
            left = inorder(node1.left,node2)
            right = inorder(node1.right,node2)
            
            return left or right
        
        return inorder(root,subRoot)
            