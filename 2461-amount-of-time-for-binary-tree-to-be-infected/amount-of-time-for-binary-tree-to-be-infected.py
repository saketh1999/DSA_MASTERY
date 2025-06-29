# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def amountOfTime(self, root: Optional[TreeNode], start: int) -> int:
        
        #construct Binary Parent Tree
        
        def construct_parent_tree(node,parent):
            nonlocal start_node
            if node is None:
                return
            parent_tree[node] = parent
            if node.val == start:
                start_node = node

            construct_parent_tree(node.left,node)
            construct_parent_tree(node.right,node)

        
        def time_to_infect(start):
            time = -1
            visited = set()
            visited.add(start)
            queue=deque([start])

            while queue:
                size_of_queue = len(queue)
                for _ in range(size_of_queue):
                    node = queue.popleft()
                    
                    if node.left and node.left not in visited:
                        queue.append(node.left)
                        visited.add(node.left)

                    if node.right and node.right not in visited:
                        queue.append(node.right)
                        visited.add(node.right)

                    if parent_tree[node]  and parent_tree[node] not in visited:
                        queue.append(parent_tree[node])
                        visited.add(parent_tree[node])

                time+=1
                    # visited = set()
                    # queue = deque([start_node])
                    # visited.add(start_node)
                    # time = -1

                    # while queue:
                    #     size = len(queue)
                    #     for _ in range(size):
                    #         node = queue.popleft()
                    #         for neighbor in (node.left, node.right, parent_tree[node]):
                    #             if neighbor and neighbor not in visited:
                    #                 visited.add(neighbor)
                    #                 queue.append(neighbor)
                    #     time += 1
            return time
                    
        parent_tree = {}    
        start_node = None
        construct_parent_tree(root,None)
        return time_to_infect(start_node)
