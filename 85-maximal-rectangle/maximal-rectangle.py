class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        row = len(matrix)
        col = len(matrix[0])
        mat = [[0 for c in range(col)] for r in range(row)]

        def prefixSum_Col(matrix):
            for c in range(col):
                prefixSum = int(matrix[0][c])
                for r in range(1,row):
                    if int(matrix[r][c])==0:
                        prefixSum=0

                    mat[r][c] = int(matrix[r][c])+prefixSum
                    prefixSum = mat[r][c]

        def AreaOfHistogram(heights):
            stack= []
            n = len(heights)
            area=0
            for i in range(len(heights)):

                while stack and heights[stack[-1]] > heights[i]:
                    nse = i
                    index = stack.pop(-1)
                    pse = stack[-1] if stack else -1
                    area= max(area,heights[index]*(nse-pse-1))
                

                stack.append(i)
            
            while stack:
                nse = n
                index = stack.pop(-1)
                pse = stack[-1] if stack else -1
                area= max(area,heights[index]*(nse-pse-1))
            
            return area

        for c in range(col):
            mat[0][c]=int(matrix[0][c])

        prefixSum_Col(matrix)
        print(mat)
        max_area = 0
        for row in mat:
            max_area = max(max_area,AreaOfHistogram(row))
            print(max_area)
        return max_area

                

                

