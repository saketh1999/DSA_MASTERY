class MinStack:

    def __init__(self):
        self.stack = []
        self.min = math.inf

    def push(self, val: int) -> None:
        if val < self.min:
            self.min = val
            self.stack.append((val,val))
        else:
            self.stack.append((val,self.min))
        

    def pop(self) -> None:
        self.stack.pop()
        if len(self.stack):
            self.min = self.stack[-1][1]
        else:
            self.min = math.inf
        

    def top(self) -> int:
        return self.stack[-1][0]
        

    def getMin(self) -> int:
        val,mini = self.stack[-1]
        return mini

        
