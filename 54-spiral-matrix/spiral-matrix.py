class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        left = 0
        right = len(matrix[0])
        top=0
        bottom = len(matrix)
        res = []
        while left<right and top<bottom:
            for i in range(left,right):
                res.append(matrix[top][i])
                print(matrix[top][i],"here1")
            top+=1
            
            for j in range(top,bottom):
                res.append(matrix[j][right-1])
                print(matrix[j][right-1],"here2")
            
            right-=1

            if not (top<bottom and right>left):
                break
            
            for k in range(right-1,left-1,-1):
                res.append(matrix[bottom-1][k])
                print(matrix[bottom-1][k],"here3")
            bottom-=1

            for l in range(bottom-1,top-1,-1):
                res.append(matrix[l][left])
                print(matrix[l][left],"here4")
                
            left+=1
        return res



            