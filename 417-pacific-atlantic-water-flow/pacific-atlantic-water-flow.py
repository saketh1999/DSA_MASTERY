class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        pacific_water = set()
        atlantic_water = set()

        row = len(heights)
        col = len(heights[0])

        def dfs(r,c,visited,prev_height):
            if r>= row or r<0 or c>=col or c<0:
                return
            if (r,c) in visited:
                return
            if heights[r][c] < prev_height:
                return
            
            visited.add((r,c))

            dfs(r+1,c,visited,heights[r][c])
            dfs(r-1,c,visited,heights[r][c])
            dfs(r,c+1,visited,heights[r][c])
            dfs(r,c-1,visited,heights[r][c])
        

        for i in range(row):
            dfs(i,0,pacific_water,heights[i][0])
            dfs(i,col-1,atlantic_water,heights[i][col-1])
        
        for i in range(col):
            dfs(0,i,pacific_water,heights[0][i])
            dfs(row-1,i,atlantic_water,heights[row-1][i])
        
        res = []
        for i in range(row):
            for j in range(col):
                if (i,j) in pacific_water and (i,j) in atlantic_water:
                    res.append([i,j])
        return res
        

            




        

