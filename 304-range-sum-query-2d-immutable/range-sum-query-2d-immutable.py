class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        self.row = len(matrix)
        self.col = len(matrix[0])

        self.pre_sum = [[0 for i in range(self.col)] for i in range(self.row) ]
        self.total = [0 for i in range(self.row)]

        for i in range(self.row):
            for j in range(self.col):
                self.total[i]+=matrix[i][j]
                self.pre_sum[i][j] = self.total[i]

        

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        sum = 0
        for i in range(row1,row2+1):
            left,right = col1,col2

            if left == 0:
                sum+=self.pre_sum[i][right]
            else:
                sum_on_left = self.pre_sum[i][left-1]
                sum_on_right =self.pre_sum[i][right]
                sum += sum_on_right-sum_on_left
        return sum


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)