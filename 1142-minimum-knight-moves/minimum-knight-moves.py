class Solution:
    def minKnightMoves(self, xc: int, yc: int) -> int:
        q = deque()
        q.append([0,0,0])
        visited=set()
        visited.add((0,0))

        while q:
            x,y,steps=q[0]
            q.popleft()

            if x==xc and y==yc:
                return steps

            dirs = [(x-1,y-2),(x-2,y-1),(x-2,y+1),(x-1,y+2),(x+1,y-2),(x+2,y-1),(x+1,y+2),(x+2,y+1)]
            for dir in dirs:
                if dir not in visited:
                    visited.add(dir)
                    q.append([dir[0],dir[1],steps+1])
            
        return -1
