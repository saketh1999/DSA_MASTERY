class Solution:
    def __init__(self):
        # Using a dictionary for 'mark' similar to unordered_map
        self.mark = {}
        # dp table initialized with -1. Max size for stones is 2000, and prevJump can also be up to 2000.
        # Python lists of lists can serve as a DP table.
        self.dp = [[-1] * 2001 for _ in range(2001)] 

    def solve(self, stones: list[int], n: int, index: int, prevJump: int) -> int:
        # If reached the last stone, return 1.
        if index == n - 1:
            return 1
        
        # If this subproblem has been already calculated, return it.
        if self.dp[index][prevJump] != -1:
            return self.dp[index][prevJump]
        
        ans = False
        # Iterate over the three possibilities {k - 1, k, k + 1}.
        for nextJump in range(prevJump - 1, prevJump + 2):
            if nextJump > 0 and (stones[index] + nextJump) in self.mark:
                # 'or' operation for boolean accumulation
                ans = ans or self.solve(stones, n, self.mark[stones[index] + nextJump], nextJump)
                # if ans:  # Optimization: if true is found, no need to check further
                #     break

        # Store the result to fetch later.
        self.dp[index][prevJump] = int(ans)  # Convert boolean to int (0 or 1) for dp table
        return self.dp[index][prevJump]
    
    def canCross(self, stones: list[int]) -> bool:
        # The first jump must be 1 unit, and the frog starts at stone 0.
        # If the second stone is not at position 1, it's impossible to cross.
        if stones[1] != 1: 
            return False
            
        # Mark stones in the map to identify if such stone exists or not.
        for i, stone in enumerate(stones):
            self.mark[stone] = i
        
        # Initial call: from stone 0, with a previous jump of 0 (this is a placeholder
        # as the first actual jump is handled within solve from stone[0] to stone[1])
        # A common way to handle the first jump of 1 is to start solve from index 1 with prevJump=1.
        # However, following the C++ code's solve signature, the 'prevJump = 0' 
        # for the initial call makes sense if the logic in 'solve' correctly handles the first step.
        # Given the problem's constraints (first jump must be 1), a more direct
        # initiation might be `solve(stones, n, 1, 1)` after checking `stones[1] == 1`.
        # However, adhering strictly to the provided C++ `solve(..., 0, 0)`, 
        # the loop `for nextJump in range(prevJump - 1, prevJump + 2)` with `prevJump = 0` 
        # will start with `nextJump = -1`, `0`, `1`. Only `nextJump = 1` will be valid.
        # This implicitly handles the first jump being 1.
        
        return bool(self.solve(stones, len(stones), 0, 0))