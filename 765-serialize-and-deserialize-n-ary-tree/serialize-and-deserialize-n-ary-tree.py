"""
# Definition for a Node.
class Node(object):
    def __init__(self, val: Optional[int] = None, children: Optional[List['Node']] = None):
        if children is None:
            children = []
        self.val = val
        self.children = children
"""

class Codec:
    def serialize(self, root: 'Node') -> str:
        """Encodes a tree to a single string.
        
        :type root: Node
        :rtype: str
        """
        self.res = []
        def tree_trav(root):

            if root is None:
                self.res.append('N')
                return

            self.res.append(str(root.val))
            for child in root.children:

                tree_trav(child)
            
            self.res.append('N')

        tree_trav(root)

        return ",".join(self.res)
        
	
    def deserialize(self, data: str) -> 'Node':
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: Node
        """
        preorder = data.split(",")
        self.i = 0

        def dfs():
            if preorder[self.i] == 'N':
                self.i+=1
                return None
            
            root = Node(int(preorder[self.i]),[])
            self.i+=1
            child=dfs()
            while child:
                root.children.append(child)
                child = dfs()
       

            return root
        
        return dfs()

        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))