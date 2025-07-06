class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        stack = []

        for i in range(len(asteroids)):

            if asteroids[i]>0:
                    stack.append(asteroids[i])

            else:
                while stack and stack[-1]>0 and abs(asteroids[i])>stack[-1]:
                        stack.pop(-1)
        
                if  stack and abs(asteroids[i]) == stack[-1]:
                        stack.pop()

                elif not stack or stack[-1]<0: #this is important - it will also allow you to insert negative values
                    stack.append(asteroids[i])

        return stack

