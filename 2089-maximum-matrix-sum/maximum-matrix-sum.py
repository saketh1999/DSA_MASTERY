class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        neg_count = 0
        row = len(matrix)
        col = len(matrix[0])
        sum=0
        mini = float("inf")
        for i in range(row):
            for j in range(col):
                if matrix[i][j]<0:
                    neg_count+=1
                mini = min(mini,abs(matrix[i][j]))
                sum+=abs(matrix[i][j])

        if neg_count%2!=0:
            sum = sum -  2*mini
        
        return sum
                
