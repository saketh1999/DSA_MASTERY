class Solution:
    def numDistinctIslands(self, grid: List[List[int]]) -> int:
        row = len(grid)
        col = len(grid[0])

        distinct_islands = set()

        visited = [[0 for _ in range(col)] for _ in range(row)]

        distances = [[1,0],[0,1],[-1,0],[0,-1]]

        

        def island(r,c,island_list):
            q = deque()
            q.append((r,c))
            visited[r][c]=1

            while q:

                r,c = q[0]
                q.popleft()

                for dr,dc in distances:
                    nr,nc = r+dr,c+dc

                    if nr<row and nr>=0 and nc>=0 and nc<col and visited[nr][nc]!=1 and grid[nr][nc]!=0:
                        visited[nr][nc]=1
                        q.append((nr,nc))

                        island_list.append([nr,nc])
                

        for i in range(row):
            for j in range(col):

                if visited[i][j]==0 and grid[i][j]==1:
                    island_list = []

                    island_list.append([i,j])
                    island(i,j,island_list)



                    for x in range(len(island_list)):
                        island_list[x][0] -= i
                        island_list[x][1] -= j


                    distinct_islands.add(tuple(tuple(x) for x in island_list))


        return len(distinct_islands)



        