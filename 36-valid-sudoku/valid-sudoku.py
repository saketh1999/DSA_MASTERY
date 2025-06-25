class Solution:
    

    def isValidSudoku(self, board: List[List[str]]) -> bool:
        
        
        row = len(board)
        col = len(board[0])

        #checking for each row
        for r in range(row):
            rowise = [0]*10
            for c in range(col):
                if board[r][c]=='.':continue
               
                if rowise[ord(board[r][c])-ord('0')]==1: return False
                rowise[ord(board[r][c])-ord('0')]=1
        
        #checking for each col
        for c in range(col):
            colwise=[0]*10

            for r in range(row):
                if board[r][c]=='.':continue
                if colwise[ord(board[r][c])-ord('0')]==1: return False
                colwise[ord(board[r][c])-ord('0')]=1
        

        #checking for every 3*3 matrix
        def checkMatrixValid(r,c):
            matrix = [0]*10

            for i in range(3):
                for j in range(3):
                    if board[i+r][j+c]=='.':continue
                    if matrix[ord(board[i+r][j+c])-ord('0')]==1:
                        return True
                    matrix[ord(board[i+r][j+c])-ord('0')]=1
            
            return False
        for r in range(3):
            for c in range(3):
                if checkMatrixValid(r*3,c*3):
                    return False
        
        return True


