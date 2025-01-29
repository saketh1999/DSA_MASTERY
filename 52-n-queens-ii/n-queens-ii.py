class Solution:
    def totalNQueens(self, n: int) -> int:

        def backtrack(row, cols, diag1, diag2):
            if row == n:
                return 1
            count = 0
            for col in range(n):
                # Check if the current column and diagonals are under attack
                if col not in cols and (row - col) not in diag1 and (row + col) not in diag2:
                    # Place the queen
                    cols.add(col)
                    diag1.add(row - col)
                    diag2.add(row + col)
                    # Move to the next row
                    count += backtrack(row + 1, cols, diag1, diag2)
                    # Backtrack (remove the queen)
                    cols.remove(col)
                    diag1.remove(row - col)
                    diag2.remove(row + col)
            return count

        return backtrack(0, set(), set(), set())
