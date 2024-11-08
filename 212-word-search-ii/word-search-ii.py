
class Trie:
    def __init__(self):
        self.children = {}
        self.word = False

    def addWord(self,word):
        curr = self
        for x in word:
            if x not in curr.children:
                curr.children[x] = Trie()
            curr = curr.children[x]
        curr.word = True

class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        row = len(board)
        col = len(board[0])

        res = set()

        myTrie = Trie()
        for x in words :
            myTrie.addWord(x)
        
        visited = [[False for i in range(col)]for j in range(row)]

        def dfs(r,c,node,curr_word):
            
            if (r<0 or c<0 or r>=row or c>=col):
                return 
            
            if visited[r][c]:
                return 
            if board[r][c] not in node.children:
                return
           
            visited[r][c] = True

            next_node = node.children[board[r][c]]
            curr_word+=board[r][c]

            if next_node.word:
                res.add(curr_word)
            
            
            dfs(r+1,c,next_node,curr_word)
            dfs(r-1,c,next_node,curr_word)
            dfs(r,c+1,next_node,curr_word)
            dfs(r,c-1,next_node,curr_word)

            visited[r][c] = False


        for i in range(row):
            for j in range(col):
                dfs(i,j,myTrie,"")
        
        return list(res)
