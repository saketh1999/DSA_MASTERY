class HitCounter:

    def __init__(self):
        self.q = deque()
        

    def hit(self, timestamp: int) -> None:
        self.q.append(("hit",timestamp))

    def getHits(self, timestamp: int) -> int:
        while self.q:
            old_timestamp = self.q[0][1]
            if timestamp-old_timestamp >= 300:
                self.q.popleft()
            else:
                break
        
        return len(self.q)


# Your HitCounter object will be instantiated and called as such:
# obj = HitCounter()
# obj.hit(timestamp)
# param_2 = obj.getHits(timestamp)