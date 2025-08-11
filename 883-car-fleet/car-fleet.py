class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:

        pos_speed = [[position[i],speed[i]]for i in range(len(position))]
        pos_speed.sort(reverse=True)
        
        time_stack = []
        for p,s in pos_speed:
            time_stack.append((target-p)/s)
            if len(time_stack)>=2 and time_stack[-1]<=time_stack[-2]:
                time_stack.pop()
        return len(time_stack)