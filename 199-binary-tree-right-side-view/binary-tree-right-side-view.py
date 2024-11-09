# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightView(self,root,depth):
        if root == None:
            return  

        if depth == len(self.res):
            self.res.append(root.val)
        
        self.rightView(root.right,depth+1)
        self.rightView(root.left,depth+1)
   
        

    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        self.res = []
        self.rightView(root,0)
        return self.res