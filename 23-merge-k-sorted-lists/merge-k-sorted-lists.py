# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:


        pq = []

        for i in range(len(lists)):
            if lists[i]:
                pq.append((lists[i].val,i))
                lists[i] = lists[i].next
        
        heap = heapq.heapify(pq)

        dummyNode = ListNode(-1)
        temp = dummyNode
        


        while pq:

           val,i = heapq.heappop(pq)

           temp.next = ListNode(val)
           temp = temp.next

           if lists[i]:
                heapq.heappush(pq,(lists[i].val,i))
                lists[i]=lists[i].next


        
        return dummyNode.next
           
       
