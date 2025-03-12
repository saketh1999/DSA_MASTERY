class DetectSquares:

    def __init__(self):
        self.points = []
        self.dict = defaultdict(int)

    def add(self, point: List[int]) -> None:
        self.points.append(point)
        if tuple(point) not in self.dict:
            self.dict[tuple(point)]=0
        self.dict[tuple(point)]+=1


    def count(self, point: List[int]) -> int:
        res = 0
        px,py=point
        for x,y in self.points:
            if abs(px-x)!=abs(py-y) or x==px or y==py:
                continue
            res+= self.dict[tuple([x,py])] * self.dict[tuple([px,y])]
        

        return res


# Your DetectSquares object will be instantiated and called as such:
# obj = DetectSquares()
# obj.add(point)
# param_2 = obj.count(point)