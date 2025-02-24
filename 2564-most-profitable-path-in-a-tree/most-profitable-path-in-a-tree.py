class Solution:
    def mostProfitablePath(self, edges: List[List[int]], bob: int, amount: List[int]) -> int:
        adjlist = defaultdict(list)
        #creating the adj list
        for u,v in edges:
            adjlist[u].append(v)
            adjlist[v].append(u)
        
        #Simulation for bob
        bob_times = {}#to keep track of the nodes and the time bob visited them
        def bob_trav(src,prev,time):
            if src == 0:
                bob_times[src]=time
                return True
            
            for nei in adjlist[src]:
                if nei == prev:
                    continue
                else:
                    
                    if bob_trav(nei,src,time+1):
                        bob_times[src] = time
                        return True
            return False
        
        bob_trav(bob,-1,0)
        #Alice Simulation
        q = deque([(0,-1,0,amount[0])]) #node, prev, time, total_profit
        res = float('-inf')
        while q:
            node,prev,time,total_profit = q.popleft()
            for nei in adjlist[node]:
                if nei == prev:
                    continue
                else:
                    nei_profit = amount[nei]
                    nei_time = time+1
                    if nei in bob_times:
                        if nei_time > bob_times[nei]:
                            nei_profit = 0
                        elif nei_time == bob_times[nei]:
                             nei_profit = nei_profit//2

                    q.append((nei,node,nei_time,total_profit+nei_profit))
                    if len(adjlist[nei])==1:
                        res = max(res,total_profit+nei_profit)
        
        return res