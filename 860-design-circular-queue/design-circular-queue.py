class DoublyLinkedList:
    def __init__(self,val,prev,next):
        self.val=val
        self.prev=prev
        self.next=next

class MyCircularQueue:

    def __init__(self, k: int):
        self.space=k
        self.left = DoublyLinkedList(-1,None,None)
        self.right = DoublyLinkedList(-1,self.left,None)
        self.left.next=self.right
        

    def enQueue(self, value: int) -> bool:
        if self.isFull():
            return False
        
        curr = DoublyLinkedList(value,None,None)
        curr.prev = self.right.prev
        curr.next = self.right
        
        self.right.prev.next = curr
        self.right.prev = curr
        self.space-=1

        return True

    def deQueue(self) -> bool:
        if self.isEmpty():
            return False
        
        self.left.next = self.left.next.next
        self.left.next.prev = self.left
        self.space+=1
     
        return True

        self.right = self.right.prev
        self.left = curr
        return True

    def Front(self) -> int:
        if self.isEmpty():
            return -1
        return self.left.next.val

    def Rear(self) -> int:
        if self.isEmpty():
            return -1
        return self.right.prev.val
        

    def isEmpty(self) -> bool:
        if self.left.next==self.right:
            return True
        return False

    def isFull(self) -> bool:
        if self.space==0:
            return True
        return False
        


# Your MyCircularQueue object will be instantiated and called as such:
# obj = MyCircularQueue(k)
# param_1 = obj.enQueue(value)
# param_2 = obj.deQueue()
# param_3 = obj.Front()
# param_4 = obj.Rear()
# param_5 = obj.isEmpty()
# param_6 = obj.isFull()