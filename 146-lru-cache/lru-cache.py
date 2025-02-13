class NodeDDL:
        def __init__(self,key,val):
            self.key = key
            self.val = val
            self.prev = None
            self.next = None 

class LRUCache:

    
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.head = NodeDDL(0,0)
        self.tail = NodeDDL(0,0)
        self.head.next,self.tail.prev = self.tail,self.head
        self.map = {}
    
    def deleteNode(self,node):
        print(node.val,node.key)
        prevNode = node.prev
        nextNode = node.next
        prevNode.next=nextNode
        nextNode.prev=prevNode
    
    def insertNodeAfterHead(self,node):
        nextNode = self.head.next
        prevNode = self.head

        prevNode.next = node
        nextNode.prev = node

        node.next=nextNode
        node.prev = prevNode

        self.head.next = node


    def get(self, key: int) -> int:
        if key in self.map:
            temp = self.map[key]
            #Since you touched it
            #Delete it from the end of the LL
            self.deleteNode(temp)
            #Now add the same node to the front
            self.insertNodeAfterHead(temp)
            
            return temp.val
        else:
            return -1
        

    def put(self, key: int, value: int) -> None:
        if key in self.map :
            temp = self.map[key]
            temp.val = value
            #Since you updated it
            #Delete it from the end of the LL
            self.deleteNode(temp)
            #Now add the same node to the front
            self.insertNodeAfterHead(temp)
            

        else:
            if len(self.map) == self.capacity:

                temp = self.tail.prev
                print(temp.val,temp.key)
                self.deleteNode(temp)
                del self.map[temp.key]
                del temp

            
            temp = NodeDDL(key,value)
            self.insertNodeAfterHead(temp)
            self.map[key]=temp
        


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)