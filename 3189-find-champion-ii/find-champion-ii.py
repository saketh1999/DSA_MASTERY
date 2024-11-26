class Solution:
    def findChampion(self, n: int, edges: List[List[int]]) -> int:
        incoming = [0]*n

        for u,v in edges:
            incoming[v] += 1
        
        champ =[]
        for i in range(n):
            if incoming[i] == 0:
                champ.append(i)
        
        if len(champ)>1:
            return -1
        else:
            return champ[0]