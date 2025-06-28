# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        res = []
        temp = []
        def nodeToLeaf(root,res):
            if root is None: 
                return
            if root.left is None and root.right is None:
                temp.append(root.val)
                s = ""
                for i in range(len(temp)):
                    if i==len(temp)-1:
                        s+=str(temp[i])
                    else:   
                        s+=str(temp[i])+"->"
                res.append(s)
            else:
                temp.append(root.val)
            
            nodeToLeaf(root.left,res)
            nodeToLeaf(root.right,res)

            temp.pop(-1)
        nodeToLeaf(root,res)
        return res
                