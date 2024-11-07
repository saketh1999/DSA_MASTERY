class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
    
        board = [['.' for i in range(n)] for j in range(n)]
        res = []
        
        col = set()
        post_d = set()
        neg_d = set()

        def queens(r):
            if r == n :
                print('hi')
                copy = ["".join(row) for row in board ]
                print(copy)
                res.append(copy)
                return
            
            for c in range(n):
             
                if c in col or (r+c) in post_d or (r-c) in neg_d:
                    continue

                col.add(c)
                post_d.add(r+c)
                neg_d.add(r-c)
                board[r][c] = 'Q'

                queens(r+1)

                col.remove(c)
                post_d.remove(r+c)
                neg_d.remove(r-c)
                board[r][c] = '.'

        queens(0)

        return res