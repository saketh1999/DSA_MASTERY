class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        row = len(board)
        col = len(board[0])

        visited_cells = [[0 for _ in range(col)] for _ in range(row)]



        def dfs(r,c,visited):
            if r>=row or r<0 or c>=col or c<0 :
                return 
            
            if board[r][c] == "X":
                return

            if visited[r][c] == 1:
                return 
            
            visited[r][c] = 1

            dfs(r+1,c,visited)
            dfs(r-1,c,visited)
            dfs(r,c+1,visited)
            dfs(r,c-1,visited)
        
        for i in range(row):
            dfs(i,0,visited_cells)
            dfs(i,col-1,visited_cells)

        for i in range(col):
            dfs(0,i,visited_cells)
            dfs(row-1,i,visited_cells)
        
        for i in range(row):
            for j in range(col):
                if visited_cells[i][j]==0 and board[i][j]=="O":
                    board[i][j]="X"




            
