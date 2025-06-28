# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def boundaryOfBinaryTree(self, root: Optional[TreeNode]) -> List[int]:
        def isLeaf(root):
            if root is None:
                return False
            if root.left is None and root.right is None:
                return True
            else:
                return False
        
        def left_boundary(root,res):
            curr = root.left
            while curr:
                if not isLeaf(curr):
                    res.append(curr.val)
                if curr.left:
                    curr=curr.left
                else:
                    curr=curr.right
            print(res)
            return res
        
        def right_boundary(root,res):
            curr = root.right
            temp = []
            while curr:
                if not isLeaf(curr):
                    temp.append(curr.val)
                if curr.right:
                    curr=curr.right
                else:
                    curr=curr.left
            
            temp.reverse()
            for x in temp:
                res.append(x)
            print(res)
            return res

        def leaf_nodes(root,res):
            if root is None:
                return res
            
            if isLeaf(root):
                res.append(root.val)
            leaf_nodes(root.left,res)
            leaf_nodes(root.right,res)
            return res

        res = []
        if root is None:
            return []
        if isLeaf(root):
            return [root.val]

        res.append(root.val)
        left_boundary(root,res)
        leaf_nodes(root,res)
        right_boundary(root,res)

        return res