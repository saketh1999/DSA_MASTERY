class Solution:


    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        def myBinarySearch(self,col_start:int,col_end:int,row:int,matrix: List[List[int]],target:int) -> bool:

            while col_start <= col_end:

                mid = (col_start+col_end)//2
                print(mid)
        
                if matrix[row][mid] == target:
                    return True

                elif matrix[row][mid] < target:
                    col_start=mid+1
                else:
                    col_end = mid-1

            return False

        n = len(matrix[0])-1


        for i in range(len(matrix)):
                if target >=  matrix[i][0] and target <= matrix[i][n]:
                 
                    col_start = 0
                    col_end = n
                    row = i

                    return myBinarySearch(self,col_start,col_end,row,matrix,target)
       

