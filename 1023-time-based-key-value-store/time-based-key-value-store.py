class TimeMap:

    def __init__(self):
        self.store = {} #storing the key: list of [value,timestamp]

    def set(self, key: str, value: str, timestamp: int) -> None:
        if key not in self.store:
            self.store[key]=[]
    
        self.store[key].append([value,timestamp])

    def get(self, key: str, timestamp: int) -> str:
        # res = ""
        
        # curr = self.store.get(key,[])
        res, curr = "", self.store.get(key, [])
        low,high=0,len(curr)-1
        while low<=high:
            m = (low+high)//2
            if curr[m][1] == timestamp:
                return curr[m][0]
            elif curr[m][1] <= timestamp:
                res = curr[m][0]
                low=m+1
            else:
                high=m-1
        return res


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)