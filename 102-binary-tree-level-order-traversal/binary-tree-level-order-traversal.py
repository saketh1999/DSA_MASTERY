# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        res = []
        my_q = collections.deque()
        my_q.append(root)

        while my_q:
            size_q = len(my_q)
            temp = []
            for i in range(size_q):
                front = my_q[0]
                my_q.popleft()
                if front:
                    temp.append(front.val)

                    if front.left is not None:
                        my_q.append(front.left)
                    if front.right is not None:
                        my_q.append(front.right)

              
            if temp:
                res.append(temp)
        return res
