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
        queue = deque()
        queue.append(root)
        queue.append(None)


        curr = root

        while queue:
            prev = curr
            curr = queue.popleft()
            
            while curr:
               
                if curr.left:
                  queue.append(curr.left)
                if curr.right:
                    queue.append(curr.right)
                
                prev = curr
                curr = queue.popleft()
            
            res.append(prev.val)


            if queue:
               queue.append(None)

        return res
                


