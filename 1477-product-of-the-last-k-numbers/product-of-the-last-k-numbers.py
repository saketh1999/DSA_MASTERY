class ProductOfNumbers:

    def __init__(self):
        self.stack = []

    def add(self, num: int) -> None:
        if num == 0:
            self.stack = []
        elif not self.stack:
            self.stack.append(num)
        else:
            self.stack.append(num*self.stack[-1])
        
        

    def getProduct(self, k: int) -> int:
        if len(self.stack)<k:
            return 0
        elif k==len(self.stack):
            return self.stack[-1]
        else:
            ind = len(self.stack)-k-1
            return self.stack[-1]//self.stack[ind]

        


# Your ProductOfNumbers object will be instantiated and called as such:
# obj = ProductOfNumbers()
# obj.add(num)
# param_2 = obj.getProduct(k)