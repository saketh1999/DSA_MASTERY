class PrefixNode:
    def __init__(self):
        self.children = {}
        self.count=0

class PrefixTree:
    def __init__(self):
        self.root = PrefixNode()
    def addWord(self,w):
        curr = self.root
        for c in w:
            if c not in curr.children:
                curr.children[c]=PrefixNode()
            curr = curr.children[c]
            curr.count+=1

    def countWords(self,pref):
        curr = self.root
        for c in pref:
            if c not in curr.children:
                return 0
            
            curr=curr.children[c]
        return curr.count

            
            
            
class Solution:
    def prefixCount(self, words: List[str], pref: str) -> int:
        prefixTree = PrefixTree()
        for w in words:
                if len(w)>=len(pref):
                    prefixTree.addWord(w)
            
        return prefixTree.countWords(pref)