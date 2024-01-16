class RandomizedSet:
    def __init__(self):
        self.ans = []

    def insert(self, val: int) -> bool:
        if val in self.ans:
            return False
        self.ans.append(val)
        return True

    def remove(self, val: int) -> bool:
        if val in self.ans:
            self.ans.remove(val)
            return True
        return False

    def getRandom(self) -> int:
        l = len(self.ans)
        x = random.randint(0,l-1)
        return self.ans[x]


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()