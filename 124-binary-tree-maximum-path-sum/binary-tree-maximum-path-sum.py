# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        max_sum = -math.inf

        def cal_sum(root):
            nonlocal max_sum

            if root is None:
                return 0
            
            left = max(0,cal_sum(root.left))
            right = max(0,cal_sum(root.right))

            max_sum = max(max_sum,root.val+left+right)

            return root.val+ max(left,right)
        cal_sum(root)
        return max_sum
