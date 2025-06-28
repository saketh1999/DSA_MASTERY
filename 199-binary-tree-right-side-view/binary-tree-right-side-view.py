# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        
        if root is None:
            return []

        res = []
        queue = []
        queue.append(root)

        curr = root

        while queue:
            size_of_queue = len(queue)
            for i in range(size_of_queue):
                node = queue.pop(0)
                if i == size_of_queue-1:
                    res.append(node.val)
                
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            

        return res
                


