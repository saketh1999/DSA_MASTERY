# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        
        # This helper function now returns True if the target is found
        # to stop unnecessary traversal.
        def findPath(node: 'TreeNode', target: 'TreeNode', path: list) -> bool:
            if not node:
                return False

            path.append(node)

            if node.val == target.val:
                return True

            # If the target is found in either subtree, we have the path.
            if findPath(node.left, target, path) or findPath(node.right, target, path):
                return True
            
            # If the target is not in this subtree, backtrack.
            path.pop()
            return False

        path_p = []
        path_q = []

        findPath(root, p, path_p)
        findPath(root, q, path_q)

        lca_node = None
        for i in range(min(len(path_p), len(path_q))):
            if path_p[i].val == path_q[i].val:
                lca_node = path_p[i]
            else:
                # The first divergence means the previous node was the LCA.
                break
        
        return lca_node