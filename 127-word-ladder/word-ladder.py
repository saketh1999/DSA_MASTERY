class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        #checking if the endWord is in the Wordlist
        if endWord not in wordList:
            return 0

        #create an Adj list for the words

        #adding begin word to the wordList
        wordList.append(beginWord)

        adjList = defaultdict(list)
        for word in wordList:
            for j in range(len(word)):
                pattern = word[:j]+'*'+word[j+1:]
                adjList[pattern].append(word)
        
        #Now do a simple bfs
        visited = set()
        q=deque()
        visited.add(beginWord)
        q.append(beginWord)
        res=1
        while q:
            for i in range(len(q)): #start to end distance of the graph (dont count the nodes on same level distance)
                word = q[0]
                q.popleft()

                if word == endWord:
                    return res
                
                for j in range(len(word)):
                    pattern = word[:j]+"*"+word[j+1:]
                    for nei in adjList[pattern]:
                        if nei not in visited:
                            q.append(nei)
                            visited.add(nei)
            res+=1 #res is nothing but the height of the graph from the start 
        
        #if you dont find the path within the BFS return 0
        #example:
        #begin : hot
        #end : dog
        #wordlist: ["hot","dog"]
        return 0

