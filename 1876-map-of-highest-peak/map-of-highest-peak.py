class Solution:
    def highestPeak(self, isWater: List[List[int]]) -> List[List[int]]:
        row = len(isWater)
        col = len(isWater[0])
        
        q = deque()
        visited = set()
        res = [[-1]*col for i in range(row)]

        for i in range(row):
            for j in range(col):
                if isWater[i][j]==1:
                    q.append([i,j])
                    visited.add((i,j))
                    res[i][j]=0

        
        directions = [[0,1],[0,-1],[-1,0],[1,0]]
        print(visited)
        while q:

            c_r,c_c = q.popleft()
            h = res[c_r][c_c]
            

            for r,c in directions:
                nr,nc = c_r+r,c_c+c

                if nr>=0 and nr<row and nc>=0 and nc<col and (nr,nc) not in visited:
                    res[nr][nc]=h+1
                    visited.add((nr,nc))
                    q.append([nr,nc])
                   
        
        
        return res


