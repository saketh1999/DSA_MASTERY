import collections

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> list[int]:
        """
        This solution finds all nodes at a distance k from a target node in a binary tree.

        The approach consists of two main parts:
        1.  First, we convert the tree into a graph by creating a map where each node
            is linked to its parent. This allows us to traverse upwards from any node,
            which is crucial for this problem. A Depth-First Search (DFS) is used
            to populate this parent map efficiently.

        2.  Second, we perform a Breadth-First Search (BFS) starting from the `target` node.
            BFS explores the graph level by level, making it ideal for finding nodes at an
            exact distance. We explore neighbors in three directions: left, right, and up (parent).
            The search continues for exactly k levels.
        """
        
        # Step 1: Build the parent map using DFS.
        # The map will store {node: parent_node}.
        parent_map = {}
        def build_parent_map(node, parent):
            if node:
                parent_map[node] = parent
                build_parent_map(node.left, node)
                build_parent_map(node.right, node)

        # Start the DFS from the root to build the map for the entire tree.
        build_parent_map(root, None)

        # Step 2: Perform BFS starting from the target node.
        # The queue will store the nodes to visit.
        queue = collections.deque([target])
        # A set to keep track of visited nodes to avoid cycles and redundant work.
        visited = {target}
        current_distance = 0

        # The BFS loop continues as long as there are nodes in the queue.
        while queue:
            # If we have reached the target distance, the nodes currently in the queue
            # are our answer. We collect their values and return.
            if current_distance == k:
                return [node.val for node in queue]

            # Process all nodes at the current level.
            level_size = len(queue)
            for _ in range(level_size):
                node = queue.popleft()

                # Explore the three neighbors: left child, right child, and parent.
                
                # Neighbor 1: Left Child
                if node.left and node.left not in visited:
                    visited.add(node.left)
                    queue.append(node.left)
                
                # Neighbor 2: Right Child
                if node.right and node.right not in visited:
                    visited.add(node.right)
                    queue.append(node.right)
                    
                # Neighbor 3: Parent
                parent = parent_map.get(node)
                if parent and parent not in visited:
                    visited.add(parent)
                    queue.append(parent)
            
            # Move to the next level.
            current_distance += 1

        # If the queue becomes empty before we reach distance k, it means no nodes
        # exist at that distance. Return an empty list.
        return []