# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def verticalOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        my_dict = defaultdict(list)
        min_val,max_val= 0,0

        def trav_tree(root,indX,indY):
            nonlocal min_val
            nonlocal max_val
            if root is None :
                return
            my_dict[indX].append([indY,root.val])
            #left
            min_val = min(min_val,indX,indY)
            max_val = max(max_val,indX,indY)

            trav_tree(root.left,indX-1,indY+1)
            trav_tree(root.right,indX+1,indY+1)

        trav_tree(root,0,0)

        res = []
        print(my_dict)
        for i in range(min_val,max_val+1):
            my_dict[i].sort(key=lambda x:x[0])
            my_list=[]
            for x in (my_dict[i]):
                my_list.append(x[1])
            if my_list:
                res.append(my_list)
        return res

