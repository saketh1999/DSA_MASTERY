class Solution:
    def magnificentSets(self, n: int, edges: List[List[int]]) -> int:
        #creating adj list
        adjlist = defaultdict(list)
        for u,v in edges: #undirected graph
            adjlist[u].append(v)
            adjlist[v].append(u)

        def get_connected_component(src):
            q = deque([src])
            component = set([src])

            while q:
                node = q.popleft()
                for nei in adjlist[node]:
                    if nei  in component:
                        continue
                    q.append(nei)
                    component.add(nei)
                    visited.add(nei)

            return component

        def longest_path(src):
            q = deque([(src,1)])
            dist = {src:1}

            while q:
                node,dis = q.popleft()
                for nei in adjlist[node]:
                    if nei in dist:
                        if dist[nei] == dis:
                            return -1
                        continue
                        
                    q.append((nei,dis+1))
                    dist[nei] = dis+1

            
            return max(dist.values())


        visited = set()
        res = 0
        #going over all the nodes
        for i in range(1,n+1): # why - we have nodes from 1 - n+1
            if i not in visited:
                visited.add(i)
                component = get_connected_component(i)
                print(component)

                #after getting the connected component
                max_cnt = 0
                for src in component:
                    path_len = longest_path(src)


                    if path_len==-1:
                        return -1
                    
                    max_cnt = max(max_cnt,path_len)

                
                res+=max_cnt
        return res


