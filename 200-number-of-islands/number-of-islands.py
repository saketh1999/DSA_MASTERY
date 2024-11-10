class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        row= len(grid)
        col = len(grid[0])
        visited = [[0 for i in range(col)] for j in range(row)]
        count = 0

        def dfs(i,j):
            if i<0 or j<0 or i>=row or j>= col or grid[i][j]=="0" or visited[i][j]==1:
                return 

            visited[i][j] = 1

            dfs(i+1,j)
            dfs(i-1,j)
            dfs(i,j+1)
            dfs(i,j-1)
        
        for i in range(row):
            for j in range(col):
                if grid[i][j] == "1" and visited[i][j]==0:
                    count+=1
                    dfs(i,j)

        return count
                