class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        row = len(matrix)
        col = len(matrix[0])
        
        zero_row=1
        for i in range(row):
            for j in range(col):
                if matrix[i][j]==0:
                    # print(i,"eh")
                    #col
                    matrix[0][j]=0
                    
                    #row
                    if i==0:
                        # print("hii")
                        zero_row=0
                    else:
                        matrix[i][0]=0
       

        for i in range(1,row):
            for j in range(1,col):

                if matrix[0][j]==0:
                    matrix[i][j]=0
                elif matrix[i][0]==0:
                    matrix[i][j]=0

        #marking first col
        for i in range(row):
            if matrix[0][0]==0:
                matrix[i][0]=0
        #marking the first row as zero
        for j in range(col):
            if zero_row==0:
                matrix[0][j]=0
        

        

        
