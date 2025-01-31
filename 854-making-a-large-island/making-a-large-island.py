class Solution:
    def largestIsland(self, grid: List[List[int]]) -> int:
        Row = len(grid)
        Col = len(grid[0])
        directions = [[0,1],[-1,0],[1,0],[0,-1]]
        size = defaultdict(int)

        def is_valid_grid(r,c):
            if r>=0 and r<Row and c>=0 and c<Col:
                return True
            return False
        
        def dfs(r,c,mark):
            visited.add((r,c))

            grid[r][c] = mark
            size = 1
            for i,j in directions:
                nr,nc = r+i,c+j

                if is_valid_grid(nr,nc) and grid[nr][nc]==1:
                    size+=dfs(nr,nc,mark)
            
            return size

           
        #Finding all the islands
        mark = 2
        visited = set()
        for i in range(Row):
            for j in range(Col):

                if grid[i][j] == 1 and (i,j) not in visited:
                    size[mark] = dfs(i,j,mark)
                mark+=1


        def connect(i,j):
            res =1
            visit = set()

            for r,c in directions:
                nr,nc = i+r,j+c
                if is_valid_grid(nr,nc) and grid[nr][nc] not in visit:
                    res += size[grid[nr][nc]]
 

                    visit.add(grid[nr][nc])
            return res




        #Now Flipping ever zero to check
        res = 0 if not size else max(size.values())
        for i in range(Row):
            for j in range(Col):
                if grid[i][j] == 0:
                    land_size = connect(i,j)
                    res = max(land_size,res)
                    # print(res)
        
        return res

