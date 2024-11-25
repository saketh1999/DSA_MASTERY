class Solution:
    def numIslands(self, matrix: List[List[str]]) -> int:
        m=len(matrix)
        n=len(matrix[0])

        
        def dfs(matrix,visited,row,col):
            matrix_row = len(matrix)
            matrix_col = len(matrix[0])

        

            visited[row][col] = 1 #marking visited

            direction = [[0,1],[-1,0],[1,0],[0,-1]] #this indicated all the four directions we want to find the islands

            for dr,dc in direction:
                nr,nc = row+dr,col+dc
                #validity check of the row and col
                if nr < matrix_row and nr>=0 and nc>=0 and nc<matrix_col :
                    if visited[nr][nc]==0 and matrix[nr][nc]=="1":
                        #check for neigh
                        dfs(matrix,visited,nr,nc)
        
        visited = [[0 for i in range(n)] for j in range(m)]
        # print(visited)
        count=0
        for i in range(m):
            for j in range(n):
                if visited[i][j]==0 and matrix[i][j]=="1": #unvisited island
                    count+=1
                    dfs(matrix,visited,i,j)
        
        return count

        