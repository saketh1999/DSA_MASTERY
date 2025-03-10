# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class FindElements:

    def __init__(self, root: Optional[TreeNode]):
        self.arr = []
        root.val = 0
        def trav(node,val):
            if node is None:
                return
            
            self.arr.append(val)
            node.val = val
            left_val =(node.val*2)+1
            trav(node.left,left_val)

            right_val = (node.val*2)+2
            trav(node.right,right_val)
        
        trav(root,0)

    def find(self, target: int) -> bool:
        return True if target in self.arr else False


# Your FindElements object will be instantiated and called as such:
# obj = FindElements(root)
# param_1 = obj.find(target)