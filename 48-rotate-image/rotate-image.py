class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        left,right = 0,len(matrix)-1

        while left<right:
            top,bottom=left,right
            for i in range(right-left):
                

                #storing the topLeft element
                topleft = matrix[top][left+i]

                #moving the bottom left to the top left
                matrix[top][left+i] = matrix[bottom-i][left]

                #moving the bottom right to bottom left
                matrix[bottom-i][left] = matrix[bottom][right-i]

                #moving the top right to bottom right
                matrix[bottom][right-i] = matrix[top+i][right]

                #moving the topleft to top right
                matrix[top+i][right] = topleft
            
            right-=1
            left+=1
        
            


        