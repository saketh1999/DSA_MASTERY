from collections import deque
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def amountOfTime(self, root: Optional[TreeNode], start: int) -> int:
        parent_tree = {}
        start_node = None

        # Single DFS to build parent mapping and find start node
        def dfs(node, parent):
            nonlocal start_node
            if node is None:
                return
            parent_tree[node] = parent
            if node.val == start:
                start_node = node
            dfs(node.left, node)
            dfs(node.right, node)

        dfs(root, None)

        # BFS to simulate infection spread
        visited = set()
        queue = deque([start_node])
        visited.add(start_node)
        time = -1

        while queue:
            size = len(queue)
            for _ in range(size):
                node = queue.popleft()
                for neighbor in (node.left, node.right, parent_tree[node]):
                    if neighbor and neighbor not in visited:
                        visited.add(neighbor)
                        queue.append(neighbor)
            time += 1

        return time
