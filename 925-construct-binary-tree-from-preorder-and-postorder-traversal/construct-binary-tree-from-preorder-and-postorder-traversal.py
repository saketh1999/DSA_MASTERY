# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def constructFromPrePost(self, preorder: List[int], postorder: List[int]) -> Optional[TreeNode]:    
        n = len(preorder)

        postorder_dir = {}
        for i in range(len(postorder)):
            postorder_dir[postorder[i]]=i
        

        def build (i1,i2,j1,j2):
            if i1>i2 or j1>j2:
                return None
            root = TreeNode(preorder[i1])
            if i1!=i2:
                left_node_val  = preorder[i1+1]
                mid_node_index = postorder_dir[left_node_val]
                len_of_left = mid_node_index-j1+1

                #building the left and right subtree
                root.left = build(i1+1,i1+len_of_left,j1,mid_node_index)

                root.right = build(i1+len_of_left+1,i2,mid_node_index+1,j2-1)
            
            return root
        
        return build(0,n-1,0,n-1)
            
