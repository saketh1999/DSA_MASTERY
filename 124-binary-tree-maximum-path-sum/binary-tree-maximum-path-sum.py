# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.max_val = -math.inf

        def cal_max_path(root):
            if root is None:
                return 0
            
            left = max(0,cal_max_path(root.left))
            right = max(0,cal_max_path(root.right))

            self.max_val = max(self.max_val, root.val+left+right)

            return root.val+max(left,right)
        
        cal_max_path(root)
        return self.max_val