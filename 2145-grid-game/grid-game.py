class Solution:
    def gridGame(self, grid: List[List[int]]) -> int:
        col = len(grid[0])
        presum1,presum2 = [0]*col,[0]*col
        presum1[0] = grid[0][0]
        presum2[0] = grid[1][0]
        for i in range(1,col):
            presum1[i] += presum1[i-1] + grid[0][i]
            presum2[i] += presum2[i-1] + grid[1][i]
        res = float('inf')
        for i in range(0,col):
            top = presum1[-1] - presum1[i]
            bottom = presum2[i-1] if i>0 else 0
            secondRobot = max(top,bottom)
            res = min(res,secondRobot)
        
        return res