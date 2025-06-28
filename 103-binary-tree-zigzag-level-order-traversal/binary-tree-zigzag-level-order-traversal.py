# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root is None:
            return []

        result = []

        queue = deque([root])

        flag = 0

        while queue:
            size_of_queue = len(queue)
            print(size_of_queue)
            curr_level_val = []

            for _ in range(size_of_queue):
                node = queue.popleft()
                curr_level_val.append(node.val)

                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            
            if flag:
                curr_level_val.reverse()
            result.append(curr_level_val)
            curr_level_val = []
            flag = not flag

        return result
                
            
