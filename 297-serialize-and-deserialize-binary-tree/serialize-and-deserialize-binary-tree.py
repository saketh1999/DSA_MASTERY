# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        self.res = []
        def tree_trav(root):
            if root is None:
                self.res.append('N')
                return

            self.res.append(str(root.val))
            tree_trav(root.left)
            tree_trav(root.right)
        tree_trav(root)

        return ",".join(self.res)

    def deserialize(self, data):

        preorder = data.split(",")
        self.i = 0

        def dfs():
            if preorder[self.i] == 'N':
                self.i+=1
                return None
            
            root = TreeNode(int(preorder[self.i]))
            self.i+=1
            root.left = dfs()
            root.right = dfs()

            return root
        
        return dfs()

        

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))